[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Changing pitch and speed of a wave file

## Before you begin:
Replace **ccSource** with valid .WAV file name.  

This code reads .WAV file, then changes its *Samples Per Second* parameter, and writes the file back under a new name defined in **ccTarget**.  
  
***  


## Code:
```foxpro  
* that is how you can notice that Homer and Barney have similar voices
#DEFINE ccSource "c:\windows\media\simpsons sounds\homer-woohoo-max.wav"
*#DEFINE ccSource "c:\windows\media\robotz open.wav"
#DEFINE ccTarget "test.wav"

DO decl

DO PlayFile WITH 1
DO PlayFile WITH 1.5
DO PlayFile WITH 2
DO PlayFile WITH 2.5
DO PlayFile WITH 0.8
DO PlayFile WITH 0.6
DO PlayFile WITH 0.2
* end of main

PROCEDURE PlayFile(nRatio)
	PRIVATE cFmtData, nDataSize, hMem, cFileInfo,;
		nChannels, nSamples, nBPS, nAvgBPS
	STORE "" TO cFmtData, cFileInfo
	STORE 0 TO nDataSize, hMem, nChannels, nSamples, nBPS, nAvgBPS

	IF Not LoadWaveFile(ccSource)
		? cFileInfo
		RETURN .F.
	ENDIF

	* changing samples per second value
	nSamples = nSamples * nRatio
	nAvgBPS = nSamples * nChannels * nBPS / 8
	cSamples = num2dword(Int(nSamples))
	cFmtData = STUFF(cFmtData, 5,4, cSamples)

	IF CreateWaveFile(ccTarget)
		SET BELL TO (ccTarget)
		?? Chr(7)
		SET BELL TO
	ENDIF

	= GlobalFree(hMem)
	= INKEY(nDataSize/nAvgBPS)
	DOEVENTS
* end of main

FUNCTION LoadWaveFile(cFile)
#DEFINE MMIO_READ  0
#DEFINE MMIO_FINDRIFF   0x0020
#DEFINE MMIO_FINDCHUNK  0x0010
#DEFINE MMIO_ALLOCBUF   0x00010000
	LOCAL hFile, cRiffInfo, cRiffType, cFmtInfo, nFmtSize,;
		cDataInfo, cMMIOINFO, nAllocSize

	* opening WAVE file
	cMMIOINFO = Repli(Chr(0), 64)
	hFile = mmioOpen(cFile, @cMMIOINFO, MMIO_READ+MMIO_ALLOCBUF)
	IF hFile = 0
		cFileInfo="Could not open file " + cFile
		RETURN .F.
	ENDIF

	* reading RIFF chunk
	cRiffInfo = Repli(Chr(0), 20)
	IF mmioDescend(hFile, @cRiffInfo, Null, MMIO_FINDRIFF) <> 0
		cFileInfo="RIFF chunk not found"
		= mmioClose(hFile, 0)
		RETURN .F.
	ENDIF

	cRiffType = SUBSTR(cRiffInfo, 9,4)
	IF cRiffType <> "WAVE"
		cFileInfo = "Not a WAVE file"
		= mmioClose(hFile, 0)
		RETURN .F.
	ENDIF

	* reading format chunk
	cFmtInfo = PADR("fmt ", 20, Chr(0))
	= mmioDescend(hFile, @cFmtInfo, @cRiffInfo, MMIO_FINDCHUNK)
	nFmtSize = buf2dword(SUBSTR(cFmtInfo, 5,4))
	cFmtData = Repli(Chr(0), nFmtSize)
	DECLARE LONG mmioRead IN winmm;
		INTEGER hmmio, STRING @pch, INTEGER cch
	= mmioRead(hFile, @cFmtData, nFmtSize)
	
	nChannels = buf2word(SUBSTR(cFmtData,3,2))
	nSamples = buf2dword(SUBSTR(cFmtData,5,4))
	nBPS = buf2word(SUBSTR(cFmtData,15,2))
	nAvgBPS = nSamples * nChannels * nBPS / 8

	= mmioAscend(hFile, @cFmtInfo, 0)

	* reading data part
	cDataInfo = PADR("data", 20, Chr(0))
	= mmioDescend(hFile, @cDataInfo, @cRiffInfo, MMIO_FINDCHUNK)

	nDataSize = buf2dword(SUBSTR(cDataInfo, 5,4))
	nAllocSize = (Int(nDataSize/1024) + 1) * 1024
	hMem = GlobalAlloc(0, nAllocSize)
	= ZeroMemory(hMem, nAllocSize)

	DECLARE LONG mmioRead IN winmm;
		INTEGER hmmio, INTEGER pch, INTEGER cch
	= mmioRead(hFile, hMem, nDataSize)
	= mmioAscend(hFile, @cDataInfo, 0)

	= mmioClose(hFile, 0)
RETURN .T.

PROCEDURE CreateWaveFile(cFilename)
#DEFINE MMIO_READWRITE  2
#DEFINE MMIO_CREATE     0x00001000
#DEFINE MMIO_ALLOCBUF   0x00010000
#DEFINE MMIO_CREATERIFF 0x0020

	LOCAL hFile, cBuffer, cRiffInfo, cFmtInfo, cDataInfo
	cBuffer = Repli(Chr(0), 64)
	hFile = mmioOpen(cFilename, @cBuffer,;
		MMIO_CREATE+MMIO_READWRITE+MMIO_ALLOCBUF)

	IF m.hFile <> 0
		* creating RIFF chunk
		cRiffInfo = Repli(Chr(0), 8) + "WAVE" + Repli(Chr(0), 8)
		= mmioCreateChunk(hFile, @cRiffInfo, MMIO_CREATERIFF)

		* creating format chunk
		cFmtInfo = PADR("fmt " + num2dword(Len(cFmtData)), 20)
		= mmioCreateChunk(hFile, @cFmtInfo, 0)
		DECLARE LONG mmioWrite IN winmm;
			INTEGER hmmio, STRING pch, LONG cch
		= mmioWrite(hFile, cFmtData, Len(cFmtData))
		= mmioAscend(hFile, @cFmtInfo, 0)  && exiting format chunk

		* creating data chunk
		cDataInfo = PADR("data" + num2dword(nDataSize), 20)
		= mmioCreateChunk(hFile, @cDataInfo, 0)
		DECLARE LONG mmioWrite IN winmm;
			INTEGER hmmio, INTEGER pch, LONG cch
		= mmioWrite(hFile, hMem, nDataSize)
		= mmioAscend(hFile, @cDataInfo, 0)  && exiting data chunk

		= mmioAscend(hFile, @cRiffInfo, 0)  && exiting RIFF chunk
		= mmioFlush(hFile, 0)  && writing I/O buffer to disk
		= mmioClose(hFile, 0)  && closing file opened with mmioOpen
	ENDIF
RETURN (m.hFile <> 0)

PROCEDURE decl
	DECLARE INTEGER mmioFlush IN winmm INTEGER hmmio, INTEGER fuFlush
	DECLARE INTEGER mmioClose IN winmm INTEGER hmmio, INTEGER wFlags
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

	DECLARE RtlZeroMemory IN kernel32 As ZeroMemory;
		INTEGER dest, INTEGER numBytes

	DECLARE INTEGER mmioOpen IN winmm;
		STRING szFilename, STRING @lpmmioinfo, INTEGER dwOpenFlags

	DECLARE INTEGER mmioAscend IN winmm;
		INTEGER hmmio, STRING @lpck, INTEGER wFlags

	DECLARE INTEGER mmioDescend IN winmm;
		INTEGER hmmio, STRING @lpck,;
		STRING @lpckParent, INTEGER wFlags

	DECLARE INTEGER mmioCreateChunk IN winmm;
		INTEGER hmmio, STRING @lpck, INTEGER wFlags

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION num2dword(lnValue)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
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
[mmioCreateChunk](../libraries/winmm/mmioCreateChunk.md)  
[mmioDescend](../libraries/winmm/mmioDescend.md)  
[mmioFlush](../libraries/winmm/mmioFlush.md)  
[mmioOpen](../libraries/winmm/mmioOpen.md)  
[mmioRead](../libraries/winmm/mmioRead.md)  
[mmioWrite](../libraries/winmm/mmioWrite.md)  
