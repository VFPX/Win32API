[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to set Creation Date/Time for a folder (WinNT)

## Before you begin:
This code sample has been translated from VB code. The original link is [Modifying the Date/Time of Folders and Files Under Windows NT+](http://www.mvps.org/vbnet/index.html) at <a href="http://www.mvps.org/vbnet/index.html">VBNet</a> developers resource centre.  
  
***  


## Code:
```foxpro  
? ChangeFolderFileDate("c:\myfolder", DATETIME())

FUNCTION ChangeFolderFileDate(cFolder, tDate)
#DEFINE GENERIC_WRITE  0x40000000
#DEFINE GENERIC_READ   0x80000000
#DEFINE FILE_SHARE_DELETE 4
#DEFINE FILE_SHARE_READ   1
#DEFINE OPEN_EXISTING     3
#DEFINE FILE_FLAG_BACKUP_SEMANTICS 0x02000000

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
		INTEGER dwShareMode, INTEGER lpSecurityAttr,;
		INTEGER dwCreationDisp, INTEGER dwFlagsAndAttrs,;
		INTEGER hTemplateFile

	LOCAL hFolder
	
	* use CreateFile for Windows NT/XP/2000 and OpenFile for Win9/Me
	hFolder = CreateFile(cFolder, GENERIC_WRITE+GENERIC_READ,;
		FILE_SHARE_READ+FILE_SHARE_DELETE, 0, OPEN_EXISTING,;
		FILE_FLAG_BACKUP_SEMANTICS, 0)

	IF hFolder = -1  && failed to open
		RETURN .F.   && use GetLastError to get an error code
	ENDIF

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER SetFileTime IN kernel32;
		INTEGER hFile, STRING lpCreationTime,;
		STRING lpLastAccessTime, STRING lpLastWriteTime

	DECLARE INTEGER SystemTimeToFileTime IN kernel32;
		STRING lpSystemTime, STRING @lpFileTime

	DECLARE INTEGER LocalFileTimeToFileTime IN kernel32;
		STRING lpLocalFileTime, STRING @lpFileTime

	LOCAL cSysTime, cFileTime, nResult
	cFileTime = Repli(Chr(0),8)

	cSysTime = num2buf(Year(tDate)) + num2buf(Month(tDate)) +;
		num2buf(DOW(tDate,0)) + num2buf(Day(tDate)) +;
		num2buf(Hour(tDate)) + num2buf(Minute(tDate)) + Repli(Chr(0),4)

	* converting SYSTEMTIME data to FILITIME
	= SystemTimeToFileTime(cSysTime, @cFileTime)
	
	* in case your local time is different from UTC
	= LocalFileTimeToFileTime(cFileTime, @cFileTime)

	* file handle, created, last-access, last-write
	nResult = SetFileTime(hFolder, cFileTime, 0,0)

	= CloseHandle(hFolder)  && important
RETURN (nResult <> 0)

FUNCTION num2buf(nValue)
RETURN Chr(MOD(m.nValue,256)) + CHR(INT(m.nValue/256))  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[LocalFileTimeToFileTime](../libraries/kernel32/LocalFileTimeToFileTime.md)  
[OpenFile](../libraries/kernel32/OpenFile.md)  
[SetFileTime](../libraries/kernel32/SetFileTime.md)  
[SystemTimeToFileTime](../libraries/kernel32/SystemTimeToFileTime.md)  
