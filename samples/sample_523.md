[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Playing WAV sounds simultaneously

## Short description:
This code is written in response to a question posted on UT: Ride two WAVs at once? As I found, the sndPlaySound was not suitable for this. To play multiple sounds simultaneously, the waveOut* functions must be used...  
***  


## Before you begin:
This code is written in response to a question posted on UT: Ride two WAVs at once?

The sndPlaySound is not suitable for this. To play multiple sounds simultaneously, the waveOut* functions must be used.  

See also:


* [WAV file player](sample_417.md)  
* [Controlling master audio volume by sending WM_APPCOMMAND messages](sample_592.md)  
* [WAV file recorder](sample_421.md)  
* [How to play MIDI notes](sample_537.md)  
  
***  


## Code:
```foxpro  
#DEFINE MMIO_READ  0
#DEFINE MMIO_FINDRIFF  0x0020
#DEFINE MMIO_FINDCHUNK  0x0010
#DEFINE MMIO_ALLOCBUF 0x00010000
#DEFINE WAVE_MAPPER  -1
#DEFINE WAVEHDR_SIZE  32

DEFINE CLASS WavPlayer As Session
	WavSounds=NULL

PROCEDURE Init
	THIS.declare
	THIS.WavSounds = CREATEOBJECT("Collection")

FUNCTION LoadWavSound(cFile As String) As Boolean
* loads wave file in memory
	LOCAL ws As WavSound, lResult
	ws = CREATEOBJECT("WavSound", m.cFile)
	
	IF ws.fileloaded
		THIS.WavSounds.Add(m.ws)
		lResult=.T.
	ELSE
		lResult=.F.
	ENDIF
	ws=NULL
RETURN m.lResult

PROCEDURE PlayWavSound(nIndex As Number)
* plays wave sound loaded in memory
* specified by the index in the collection
	IF BETWEEN(nIndex, 1, THIS.WavSounds.Count)
		LOCAL ws As WavSound
		ws = THIS.WavSounds.Item(m.nIndex)
		ws.PlaySound
	ENDIF

PROCEDURE AbortPlaying(nIndex As Number)
* aborts playing wave sound
* specified by the index in the collection
	IF BETWEEN(nIndex, 1, THIS.WavSounds.Count)
		LOCAL ws As WavSound
		ws = THIS.WavSounds.Item(m.nIndex)
		ws.CloseDevice
	ENDIF

PROCEDURE declare
	DECLARE INTEGER waveOutReset IN winmm INTEGER hwo
	DECLARE INTEGER waveOutClose IN winmm INTEGER hwo
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER wFlags, INTEGER dwBytes

	DECLARE INTEGER mmioClose IN winmm;
		INTEGER hmmio, INTEGER wFlags

	DECLARE RtlZeroMemory IN kernel32 As ZeroMemory;
		INTEGER dest, INTEGER numBytes

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		INTEGER Dest, STRING Source, INTEGER nLen

	DECLARE INTEGER mmioOpen IN winmm;
		STRING szFilename, STRING @lpmmioinfo,;
		INTEGER dwOpenFlags

	DECLARE INTEGER mmioAscend IN winmm;
		INTEGER hmmio, STRING @lpck, INTEGER wFlags

	DECLARE INTEGER mmioDescend IN winmm;
		INTEGER hmmio, STRING @lpck,;
		STRING @lpckParent, INTEGER wFlags

	* mmioRead is declared twice; supported starting VFP8
	* for older VFP versions need to be re-declare
	* before each call requiring different interface
	DECLARE LONG mmioRead IN winmm AS mmioReadStr;
		INTEGER hmmio, STRING @pch, INTEGER cch

	DECLARE LONG mmioRead IN winmm AS mmioReadPtr;
		INTEGER hmmio, INTEGER pch, INTEGER cch

	DECLARE INTEGER waveOutOpen IN winmm;
		INTEGER @phwo, INTEGER uDeviceID, STRING @pwfx,;
		INTEGER dwCallback, INTEGER dwCallbackInst, INTEGER fdwOpen

	DECLARE INTEGER waveOutWrite IN winmm;
		INTEGER hwo, INTEGER pwh, INTEGER cbwh

	DECLARE INTEGER waveOutPrepareHeader IN winmm;
		INTEGER hwo, INTEGER pwh, INTEGER cbwh

	DECLARE INTEGER waveOutUnprepareHeader IN winmm;
		INTEGER hwi, INTEGER pwh, INTEGER cbwh

	DECLARE INTEGER waveOutGetPitch IN winmm;
		INTEGER hwo, LONG @pdwPitch

ENDDEFINE

DEFINE CLASS WavSound As Session
PROTECTED hMem, hDevice, hWaveHdr, FmtData, DataSize
	FmtData=""
	hDevice=0
	hWaveHdr=0
	hMem=0
	DataSize=0
	errorno=0
	errormsg=""
	fileloaded=.F.

PROCEDURE Init(cFile As String)
	THIS.fileloaded = THIS.LoadWaveFile(m.cFile)
	THIS.hWaveHdr = GlobalAlloc(0, WAVEHDR_SIZE)

PROCEDURE Destroy
	THIS.CloseDevice
	THIS.ReleaseData
	= GlobalFree(THIS.hWaveHdr)

PROCEDURE CloseDevice
* closes the waveform-audio output device
	IF THIS.hDevice <> 0
		= waveOutReset(THIS.hDevice)

		= waveOutUnprepareHeader(THIS.hDevice,;
			THIS.hWaveHdr, WAVEHDR_SIZE)

		= waveOutClose(THIS.hDevice)
		THIS.hDevice = 0
	ENDIF

PROCEDURE ReleaseData
* releases memory block allocated to store WAVE data
	IF THIS.hMem <> 0
		= GlobalFree(THIS.hMem)
		THIS.hMem = 0
	ENDIF

PROTECTED PROCEDURE ResetError
	THIS.SetError(0, "")

PROTECTED PROCEDURE SetError(nError, cMsg)
	THIS.errorno = m.nError
	THIS.errormsg = m.cMsg

PROCEDURE PlaySound
	IF NOT THIS.fileloaded
		RETURN
	ENDIF
	
	THIS.CloseDevice

	LOCAL hDevice, cWaveHdr, cFmtData
	hDevice=0
	cFmtData=THIS.FmtData

	IF waveOutOpen(@hDevice, WAVE_MAPPER, @cFmtData, 0,0,0) = 0
		THIS.hDevice = hDevice

		cWaveHdr = num2dword(THIS.hMem) +;
			num2dword(THIS.DataSize) + REPLICATE(Chr(0),24)

		= CopyMemory(THIS.hWaveHdr, m.cWaveHdr, WAVEHDR_SIZE)

		= waveOutReset(hDevice)
		= waveOutPrepareHeader(hDevice, THIS.hWaveHdr,;
			WAVEHDR_SIZE)

		IF waveOutWrite(hDevice, THIS.hWaveHdr, WAVEHDR_SIZE) = 0
		* playback begins
			RETURN .T.
		ELSE
		* playback failed to start
			THIS.SetError(-1, "waveOutWrite call failed.")
			THIS.CloseDevice
			RETURN .F.
		ENDIF
	ENDIF

FUNCTION GetPitch() As Number
* 8=MMSYSERR_NOTSUPPORTED
	IF THIS.hDevice=0
		RETURN -2
	ENDIF

	LOCAL nResult, nPitch
	nPitch=0
	nResult = waveOutGetPitch(THIS.hDevice, @nPitch)
RETURN IIF(m.nResult=0, m.nPitch, -1)

PROTECTED FUNCTION LoadWaveFile(cFile) As Boolean
	THIS.ResetError

	LOCAL hFile, cRiffInfo, cRiffType, cFmtInfo, nFmtSize,;
		cFmtData, cDataInfo, nDataSize, cMMIOINFO, nAllocSize

	* opening WAVE file
	cMMIOINFO = REPLICATE(Chr(0), 64)
	hFile = mmioOpen(cFile, @cMMIOINFO, MMIO_READ+MMIO_ALLOCBUF)
	IF hFile = 0
		THIS.SetError(-1, "File " + m.cFile + " failed to open.")
		RETURN .F.
	ENDIF

	* reading RIFF chunk
	cRiffInfo = REPLICATE(CHR(0), 20)
	IF mmioDescend(hFile, @cRiffInfo, NULL, MMIO_FINDRIFF) <> 0
		THIS.SetError(-1, "RIFF chunk not found")
		= mmioClose(hFile, 0)
		RETURN .F.
	ENDIF

	cRiffType = SUBSTR(cRiffInfo, 9,4)
	IF cRiffType <> "WAVE"
		THIS.SetError(-1, "Not a WAVE file")
		= mmioClose(hFile, 0)
		RETURN .F.
	ENDIF

	* reading FMT chunk
	cFmtInfo = PADR("fmt ", 20, Chr(0))
	= mmioDescend(hFile, @cFmtInfo, @cRiffInfo, MMIO_FINDCHUNK)

	* saving format information for waveOutOpen call
	nFmtSize = buf2dword(SUBSTR(cFmtInfo, 5,4))
	cFmtData = REPLICATE(Chr(0), nFmtSize)

	= mmioReadStr(hFile, @cFmtData, nFmtSize)
	THIS.FmtData = cFmtData
	
	= mmioAscend(hFile, @cFmtInfo, 0)

	* reading data for waveOutWrite call
	cDataInfo = PADR("data", 20, Chr(0))
	= mmioDescend(hFile, @cDataInfo, @cRiffInfo, MMIO_FINDCHUNK)

	* allocating memory for WAVE data
	nDataSize = buf2dword(SUBSTR(cDataInfo, 5,4))
	THIS.DataSize = nDataSize
	nAllocSize = (Int(nDataSize/1024) + 1) * 1024

	THIS.hMem = GlobalAlloc(0, nAllocSize)
	= ZeroMemory(THIS.hMem, nAllocSize)

	= mmioReadPtr(hFile, THIS.hMem, nDataSize)
	= mmioAscend(hFile, @cDataInfo, 0)
	= mmioClose(hFile, 0)
RETURN .T.

ENDDEFINE

FUNCTION buf2dword(cBuf)
RETURN Asc(SUBSTR(cBuf, 1,1)) + BitLS(Asc(SUBS(cBuf,2,1)),8) +;
	BitLS(Asc(SUBS(cBuf,3,1)),16) + BitLS(Asc(SUBS(cBuf,4,1)),24)

FUNCTION num2dword(lnValue)
#DEFINE m0 0x100
#DEFINE m1 0x10000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[mmioAscend](../libraries/winmm/mmioAscend.md)  
[mmioClose](../libraries/winmm/mmioClose.md)  
[mmioDescend](../libraries/winmm/mmioDescend.md)  
[mmioOpen](../libraries/winmm/mmioOpen.md)  
[mmioRead](../libraries/winmm/mmioRead.md)  
[waveOutClose](../libraries/winmm/waveOutClose.md)  
[waveOutOpen](../libraries/winmm/waveOutOpen.md)  
[waveOutPrepareHeader](../libraries/winmm/waveOutPrepareHeader.md)  
[waveOutReset](../libraries/winmm/waveOutReset.md)  
[waveOutUnprepareHeader](../libraries/winmm/waveOutUnprepareHeader.md)  
[waveOutWrite](../libraries/winmm/waveOutWrite.md)  

## Comment:
The code above contains two classes. The *WavPlayer* class wraps API declarations and acts as a factory for creating instances of the *WavSound* class.   
  
On Init, an instance of * WavSound* opens specified WAV file, loads it in memory, and makes ready to be played.  
  
Here is a code for testing WavPlayer and WavSound classes.  
```foxpro
PUBLIC wp As WavPlayer  
wp = CREATEOBJECT("WavPlayer")  
  
wp.LoadWavSound("C:\WINDOWS\Media\Windows XP Logoff Sound.wav")  
wp.LoadWavSound("C:\WINDOWS\Media\Windows XP Startup.wav")  
wp.LoadWavSound("C:\WINDOWS\Media\Windows XP Logon Sound.wav")  
wp.LoadWavSound("C:\WINDOWS\Media\tada.wav")  
wp.LoadWavSound("C:\WINDOWS\Media\notify.wav")  
wp.LoadWavSound("C:\WINDOWS\Media\chord.wav")  
wp.LoadWavSound("C:\WINDOWS\Media\Windows XP Shutdown.wav")  
  
FOR nTimes=1 TO 1  
	FOR nIndex=1 TO wp.WavSounds.Count  
		wp.PlayWavSound(m.nIndex)  
		= INKEY(0.1)  
	NEXT  
NEXT
```
Note that *wp* variable must not be released while the sounds are being played. For that reason it is declared PUBLIC.  
  
API function mmioRead is declared twice with two different interfaces. In VFP versions 3 to 7, these declarations must be moved to LoadWaveFile method of WavSound class and placed each before corresponding call.  
  
***  

