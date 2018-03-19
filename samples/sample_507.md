[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating MIDI output devices

## Before you begin:
See also:

* [How to play MIDI notes](sample_537.md)  
  
***  


## Code:
```foxpro  
DO declare

LOCAL nCount, nIndex, nBufsize, cBuffer

nCount = midiOutGetNumDevs()
FOR nIndex=0 TO nCount-1
	nBufsize = 1024
	cBuffer = REPLICATE(CHR(0), nBufsize)

	IF midiOutGetDevCaps(nIndex, @cBuffer, nBufsize) = 0
		LOCAL oMidiOutCaps As MIDIOUTCAPS
		oMidiOutCaps = CREATEOBJECT("MIDIOUTCAPS", cBuffer)
		? oMidiOutCaps.szPname
	ENDIF
NEXT
* end of main

PROCEDURE declare
	DECLARE INTEGER midiOutGetNumDevs IN Winmm

	DECLARE INTEGER midiOutOpen IN Winmm;
		INTEGER @lphmo, INTEGER uDeviceID, INTEGER dwCallback,;
		INTEGER dwCallbackInstance, INTEGER dwFlags

	DECLARE INTEGER midiOutClose IN Winmm INTEGER hmo

	DECLARE INTEGER midiOutGetDevCaps IN Winmm;
		INTEGER uDeviceID, STRING @lpMidiOutCaps,;
		INTEGER cbMidiOutCaps

DEFINE CLASS MIDIOUTCAPS As Session
#DEFINE MAXPNAMELEN 32
	wMid=0
	wPid=0
	vDriverVersion=0
	szPname=""
	wTechnology=0
	wVoices=0
	wNotes=0
	wChannelMask=0
	dwSupport=0

PROCEDURE Init(cBuffer)
	THIS.wMid = buf2word(SUBSTR(cBuffer, 1, 2))
	THIS.wPid = buf2word(SUBSTR(cBuffer, 3, 2))
	THIS.vDriverVersion = buf2dword(SUBSTR(cBuffer, 5, 4))

	THIS.szPname = SUBSTR(cBuffer, 9, MAXPNAMELEN) + CHR(0)
	THIS.szPname = SUBSTR(THIS.szPname, 1, AT(CHR(0),THIS.szPname)-1)

	THIS.wTechnology = buf2word(SUBSTR(cBuffer, MAXPNAMELEN+9, 2))
	THIS.wVoices = buf2word(SUBSTR(cBuffer, MAXPNAMELEN+11, 2))
	THIS.wNotes = buf2word(SUBSTR(cBuffer, MAXPNAMELEN+13, 2))
	THIS.wChannelMask = buf2word(SUBSTR(cBuffer, MAXPNAMELEN+15, 2))
	THIS.dwSupport = buf2dword(SUBSTR(cBuffer, MAXPNAMELEN+17, 4))

ENDDEFINE

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256  
```  
***  


## Listed functions:
[midiOutClose](../libraries/winmm/midiOutClose.md)  
[midiOutGetDevCaps](../libraries/winmm/midiOutGetDevCaps.md)  
[midiOutGetNumDevs](../libraries/winmm/midiOutGetNumDevs.md)  
[midiOutOpen](../libraries/winmm/midiOutOpen.md)  
