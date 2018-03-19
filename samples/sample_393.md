[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Quering waveform-audio output devices

## Before you begin:
See also:

* [Enumerating devices installed on the local machine](sample_545.md)  
  
***  


## Code:
```foxpro  
#DEFINE MMSYSERR_NOERROR 0
DO declare

LOCAL nDevCount, nDevIndex

nDevCount = waveOutGetNumDevs()

IF nDevCount < 1
* no waveform-audio output devices found
	RETURN
ENDIF

CREATE CURSOR csDevices (mid I, pid I, drvver I,;
	devname C(32), formats I, channels I)

FOR nDevIndex=0 TO nDevCount-1
	DO QueryDevice WITH nDevIndex
ENDFOR

SELECT csDevices
GO TOP
BROWSE NORMAL NOWAIT
* end of main

PROCEDURE QueryDevice(nIndex)

*|typedef struct {
*|    WORD      wMid;                 0:2
*|    WORD      wPid;                 2:2
*|    MMVERSION vDriverVersion;       4:4
*|    TCHAR     szPname[MAXPNAMELEN]; 8:32
*|    DWORD     dwFormats;           40:4
*|    WORD      wChannels;           44:2
*|    WORD      wReserved1;          46:2
*|    DWORD     dwSupport;           48:4
*|} WAVEOUTCAPS; total 52 bytes

#DEFINE WAVEOUTCAPS_SIZE 52

	LOCAL cBuffer, nResult
	cBuffer = Repli(Chr(0), WAVEOUTCAPS_SIZE)

	nResult = waveOutGetDevCaps(nIndex,;
		@cBuffer, WAVEOUTCAPS_SIZE)

	IF nResult <> MMSYSERR_NOERROR
		? "Error:", GetWaveError(nResult)
		RETURN
	ENDIF
	
	LOCAL mid, pid, drvver, devname,;
		formats, channels

	mid = buf2word(SUBSTR(cBuffer, 1,2))
	pid = buf2word(SUBSTR(cBuffer, 3,2))

	drvver = buf2dword(SUBSTR(cBuffer, 5,4))

	devname = SUBSTR(cBuffer, 9,32)
	devname = SUBSTR(m.devname, 1, AT(Chr(0),m.devname)-1)

	formats = buf2dword(SUBSTR(cBuffer, 41,4))
	channels = buf2word(SUBSTR(cBuffer, 45,2))
	
	INSERT INTO csDevices VALUES (m.mid, m.pid, m.drvver,;
		m.devname, m.formats, m.channels)

FUNCTION GetWaveError(lnError)
	LOCAL lcBuf
	lcBuf = Repli(Chr(0), 250)
	= waveOutGetErrorText(lnError, @lcBuf, Len(lcBuf))
RETURN STRTRAN(lcBuf, Chr(0),"")

PROCEDURE declare
	DECLARE INTEGER waveOutGetNumDevs IN winmm

	DECLARE INTEGER waveOutGetDevCaps IN winmm;
		INTEGER uDeviceID, STRING @pwoc, LONG cbwoc

	DECLARE INTEGER waveOutGetErrorText IN winmm;
		INTEGER mmrError, STRING @pszText, LONG cchText

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256  
```  
***  


## Listed functions:
[waveOutGetDevCaps](../libraries/winmm/waveOutGetDevCaps.md)  
[waveOutGetErrorText](../libraries/winmm/waveOutGetErrorText.md)  
[waveOutGetNumDevs](../libraries/winmm/waveOutGetNumDevs.md)  

## Comment:
The device name the call returns (szPname[MAXPNAMELEN]) is cut off after 31st character.  
  
Using *EnumAudioEndpoints* method of <a href="http://msdn.microsoft.com/en-us/library/windows/desktop/dd371399(v=vs.85).aspx">IMMDeviceEnumerator interface</a> is another option.  
  
***  

