[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# A procedure for setting file times

## Code:
```foxpro  
*| PROCEDURE  WinSetFileTime
LPARAMETERS m.uFl, m.cTimeType, m.nYear, m.nMonth,;
	m.nDay, m.nHour, m.nMinute, m.nSec, m.nThou
	
#DEFINE OF_READWRITE     2

	LOCAL m.lpFileInformation, m.cS, m.nPar, m.fh,;
		m.lpFileInformation, m.lpSYSTIME, m.cCreation,;
		m.cLastAccess, m.cLastWrite, m.cBuffTime, m.cBuffTime1,;
		m.cTT,m.nYear1, m.nMonth1, m.nDay1, m.nHour1,;
		m.nMinute1, m.nSec1, m.nThou1

	m.nPar=PARAMETERS()
	IF m.nPar < 1
		RETURN .F.
	ENDIF

	DO decl		&& declare external functions

	m.cTT=IIF(m.nPar>=2 AND TYPE("m.cTimeType")="C";
		AND !EMPTY(m.cTimeType),LOWER(SUBSTR(m.cTimeType,1,1)),"c")

	m.nYear1=IIF(m.nPar>=3 AND TYPE("m.nYear")$"FIN";
		AND m.nYear>=1800,ROUND(m.nYear,0),-1)

	m.nMonth1=IIF(m.nPar>=4 AND TYPE("m.nMonth")$"FIN";
		AND BETWEEN(m.nMonth,1,12),ROUND(m.nMonth,0),-1)

	m.nDay1=IIF(m.nPar>=5 AND TYPE("m.nDay")$"FIN";
		AND BETWEEN(m.nDay,1,31),ROUND(m.nDay,0),-1)

	m.nHour1=IIF(m.nPar>=6 AND TYPE("m.nHour")$"FIN";
		AND BETWEEN(m.nHour,0,23),ROUND(m.nHour,0),-1)

	m.nMinute1=IIF(m.nPar>=7 AND TYPE("m.nMinute")$"FIN";
		AND BETWEEN(m.nMinute,0,59),ROUND(m.nMinute,0),-1)

	m.nSec1=IIF(m.nPar>=8 AND TYPE("m.nSec")$"FIN";
		AND BETWEEN(m.nSec,0,59),ROUND(m.nSec,0),-1)

	m.nThou1=IIF(m.nPar>=9 AND TYPE("m.nThou")$"FIN";
		AND BETWEEN(m.nThou,0,999),ROUND(m.nThou,0),-1)

	m.lpFileInformation = REPLI (CHR(0), 53)	&& just a buffer
	m.lpSYSTIME = REPLI (CHR(0), 16)			&& just a buffer

	IF GetFileAttributesEx (m.uFl, 0, @lpFileInformation) = 0
		RETURN .F.
	ENDIF

	m.cCreation   = SUBSTR(m.lpFileInformation,5,8)
	m.cLastAccess = SUBSTR(m.lpFileInformation,13,8)
	m.cLastWrite  = SUBSTR(m.lpFileInformation,21,8)
	m.cBuffTime   = IIF(m.cTT="w",m.cLastWrite,;
		IIF(m.cTT="a",m.cLastAccess,m.cCreation))

	FileTimeToSystemTime(m.cBuffTime, @lpSYSTIME)

	m.lpSYSTIME=;
		IIF(m.nYear1>=0,Int2Word(m.nYear1),SUBSTR(m.lpSYSTIME,1,2))+;
		IIF(m.nMonth1>=0,Int2Word(m.nMonth1),SUBSTR(m.lpSYSTIME,3,2))+;
		SUBSTR(m.lpSYSTIME,5,2)+;
		IIF(m.nDay1>=0,Int2Word(m.nDay1),SUBSTR(m.lpSYSTIME,7,2))+;
		IIF(m.nHour1>=0,Int2Word(m.nHour1),SUBSTR(m.lpSYSTIME,9,2))+;
		IIF(m.nMinute1>=0,Int2Word(m.nMinute1),SUBSTR(m.lpSYSTIME,11,2))+;
		IIF(m.nSec1>=0,Int2Word(m.nSec1),SUBSTR(m.lpSYSTIME,13,2))+;
		IIF(m.nThou1>=0,Int2Word(m.nThou1),SUBSTR(m.lpSYSTIME,15,2))

	SystemTimeToFileTime(m.lpSYSTIME,@cBuffTime)

	m.cBuffTime1=m.cBuffTime
	LocalFileTimeToFileTime(m.cBuffTime1,@cBuffTime)

	DO CASE
	CASE m.cTT = "w"
		m.cLastWrite=m.cBuffTime
	CASE m.cTT = "a"
		m.cLastAccess=m.cBuffTime
	OTHERWISE
		m.cCreation=m.cBuffTime
	ENDCASE

	m.fh = _lopen (m.uFl, OF_READWRITE)

	IF m.fh < 0
		RETURN .F.
	ENDIF

	SetFileTime (m.fh,m.cCreation,;
		m.cLastAccess, m.cLastWrite)

	_lclose(m.fh)
RETURN .T.

PROCEDURE Int2Word
LPARAMETERS m.nVal
RETURN Chr(MOD(m.nVal,256)) + CHR(INT(m.nVal/256))

PROCEDURE  decl
	DECLARE INTEGER SetFileTime IN kernel32;
		INTEGER hFile,;
		STRING  lpCreationTime,;
		STRING  lpLastAccessTime,;
		STRING  lpLastWriteTime

	DECLARE INTEGER GetFileAttributesEx IN kernel32;
		STRING  lpFileName,;
		INTEGER fInfoLevelId,;
		STRING  @ lpFileInformation

	DECLARE INTEGER LocalFileTimeToFileTime IN kernel32;
		STRING LOCALFILETIME,;
		STRING @ FILETIME

	DECLARE INTEGER FileTimeToSystemTime IN kernel32;
		STRING FILETIME,;
		STRING @ SYSTEMTIME

	DECLARE INTEGER SystemTimeToFileTime IN kernel32;
		STRING  lpSYSTEMTIME,;
		STRING  @ FILETIME

	DECLARE INTEGER _lopen IN kernel32;
		STRING  lpFileName, INTEGER iReadWrite

	DECLARE INTEGER _lclose IN kernel32 INTEGER hFile  
```  
***  


## Listed functions:
[FileTimeToSystemTime](../libraries/kernel32/FileTimeToSystemTime.md)  
[GetFileAttributesEx](../libraries/kernel32/GetFileAttributesEx.md)  
[LocalFileTimeToFileTime](../libraries/kernel32/LocalFileTimeToFileTime.md)  
[SetFileTime](../libraries/kernel32/SetFileTime.md)  
[SystemTimeToFileTime](../libraries/kernel32/SystemTimeToFileTime.md)  
[_lclose](../libraries/kernel32/_lclose.md)  
[_lopen](../libraries/kernel32/_lopen.md)  

## Comment:
This code has been contributed by <A href="mailto:asvlg@pbank.lg.ua">Sergey Akhmetchik</A>.  
  
**Usage:**  
   m.lRsltC=WinSetFileTime("C:\My Documents\My Music\beck.bmp",;  
   "c",2001,08,29,18,01,01,300)  
  
   m.lRsltW=WinSetFileTime("C:\My Documents\My Music\beck.bmp",;  
   "w",2001,08,29,18,01,04,000)  
  
   m.lRsltA=WinSetFileTime("C:\My Documents\My Music\beck.bmp",;  
   "a",2001,08,30,0,0,0,000)  
  
m.cTimeType  
c - creation (default)  
a - access  
w - write  
  
Precision (verified for WinME):  
Last Write Time is 2 seconds (rounded to top value)  
Last Access Time is day  
Creation Time is 10 milliseconds  
  
  
***  

