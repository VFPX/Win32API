[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Locking and unlocking file of a VFP table

## Code:
```foxpro  
DO decl

#DEFINE GENERIC_READ 0x80000000
#DEFINE GENERIC_WRITE 0x40000000
#DEFINE cret  Chr(13)
#DEFINE dcret Chr(13)+Chr(13)

	LOCAL lcPath, lcAlias, lcFile, hFile, lnHeader, lcBuffer
	lcPath  = GetTmpPath()
	lcAlias = "Test"
	lcFile  = lcPath + lcAlias + ".dbf"

	* creating a testing table
	IF USED (lcAlias)
		USE IN (lcAlias)
	ENDIF

	IF Not FILE(lcFile)
		SET SAFETY OFF
		CREATE TABLE (lcFile) (dt T)
		SET SAFETY ON
		INSERT INTO (lcAlias) VALUES (datetime())
	ELSE
		USE (lcFile) ALIAS (lcAlias) SHARED
	ENDIF

	lnHeader = HEADER()
	USE IN (lcAlias)

	lcBuffer = REPLI (Chr(0), 250)
	hFile = OpenFile (lcFile, @lcBuffer, GENERIC_READ)

	IF LockFile (hFile, 0,0, lnHeader,0) <> 0
		= MessageB ("File " + lcFile + " is locked." + dcret +;
			"At this point do not close this Dialog " +;
			"and start another VFP instance." + dcret +;
			"Use another instance to open " + lcFile + cret +;
			"or just try to read the tables on " + lcPath + " " + ;
			"using regular DIRECTORY command." + dcret +;
			"After that click Ok to unlock the target file.", 64, "Locking a file")

		= UnlockFile (hFile, 0,0, lnHeader,0)
	ELSE
		* 6 = ERROR_INVALID_HANDLE - already in exclusive use
		? "Error code:", GetLastError()
	ENDIF
	= CloseHandle (hFile)

FUNCTION  GetTmpPath
	LOCAL lpBuffer, lnLength
	lpBuffer = SPACE(250)
	lnLength = GetTempPath (LEN(lpBuffer), @lpBuffer)
RETURN Iif (lnLength=0, "C:\Temp", PADR(lpBuffer, lnLength))

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER GetTempPath IN kernel32;
		INTEGER nBufferLength, STRING @ lpBuffer

	DECLARE INTEGER LockFile IN kernel32;
		INTEGER hFile, INTEGER dwFileOffsetLow,;
		INTEGER dwFileOffsetHigh,;
		INTEGER nNumberOfBytesToLockLow,;
		INTEGER nNumberOfBytesToLockHigh

	DECLARE INTEGER UnlockFile IN kernel32;
		INTEGER hFile, INTEGER dwFileOffsetLow,;
		INTEGER dwFileOffsetHigh,;
		INTEGER nNumberOfBytesToUnlockLow,;
		INTEGER nNumberOfBytesToUnlockHigh

	DECLARE INTEGER OpenFile IN kernel32;
		STRING   lpFileName,;
		STRING @ lpReOpenBuff,;
		INTEGER  wStyle

	DECLARE INTEGER CloseHandle IN kernel32;
		INTEGER hObject  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetTempPath](../libraries/kernel32/GetTempPath.md)  
[LockFile](../libraries/kernel32/LockFile.md)  
[OpenFile](../libraries/kernel32/OpenFile.md)  
[UnlockFile](../libraries/kernel32/UnlockFile.md)  

## Comment:
After being locked in this way the table is not available to other VFP instances. You can lock it if the table is not in exclusive use.  
  
In this example I use the HEADER() function to set the number of locked bytes. It is not critical, you may choose any reasonable number of bytes to lock.  
  
***  

