[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Testing serial ports

## Short description:
In Windows all input/output ports are presented as files, so work with ports is performed through file functions like *CreateFile, CloseHandle, ReadFile, ReadFileEx, WriteFile* and *WriteFileEx*.  
***  


## Before you begin:
Another example: [Enumerating the ports that are available for printing on a specified server](sample_334.md)
  
***  


## Code:
```foxpro  
DO decl

LOCAL nIndex, cPort
FOR nIndex=1 TO 8
	cPort = "COM" + TRANSFORM(nIndex)
	? "Testing port " + m.cPort + ":", TestPort(m.cPort)
ENDFOR
* end of main

FUNCTION TestPort(cPort)
#DEFINE FILE_SHARE_READ   1
#DEFINE FILE_SHARE_WRITE  2
#DEFINE OPEN_EXISTING     3
#DEFINE GENERIC_READ      0x80000000
#DEFINE GENERIC_WRITE     0x40000000
#DEFINE FILE_FLAG_OVERLAPPED 0x40000000
#DEFINE INVALID_HANDLE_VALUE -1
#DEFINE FILE_ATTRIBUTE_NORMAL 128

	LOCAL hPort, lnErr

*	hPort = CreateFile(cPort, GENERIC_READ, 0,0,;
		OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0)

	hPort = CreateFile(cPort,;
		BITOR(GENERIC_READ,GENERIC_WRITE),;
		0,0, OPEN_EXISTING,;
		BITOR(FILE_FLAG_OVERLAPPED,FILE_ATTRIBUTE_NORMAL), 0)

	IF hPort = INVALID_HANDLE_VALUE
		lnErr = GetLastError()
		RETURN "Error " + TRANSFORM(lnErr) +;
			". " + GetErrorMessage(lnErr)
	ELSE
		= CloseHandle(hPort)
		RETURN "Ok"
	ENDIF

PROCEDURE decl
	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwAccess, INTEGER dwShareMode,;
		INTEGER lpSecurityAttr, INTEGER dwCreationDisp,;
		INTEGER dwFlagsAndAttr, INTEGER hTemplateFile

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER FormatMessage IN kernel32;
		INTEGER dwFlags, INTEGER lpSource, INTEGER dwMessageId,;
		INTEGER dwLanguageId, INTEGER @lpBuffer,;
		INTEGER nSize, INTEGER Arguments

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Destination, INTEGER Source, INTEGER nLength

FUNCTION GetErrorMessage(lnErr)
#DEFINE FORMAT_MESSAGE_ALLOCATE_BUFFER 256
#DEFINE FORMAT_MESSAGE_FROM_SYSTEM     4096
#DEFINE FORMAT_MESSAGE_IGNORE_INSERTS  512

	LOCAL dwFlags, lpBuffer, lnLength, lpResult
	dwFlags = FORMAT_MESSAGE_ALLOCATE_BUFFER +;
		FORMAT_MESSAGE_FROM_SYSTEM + FORMAT_MESSAGE_IGNORE_INSERTS

	lpBuffer = 0
	lnLength = FormatMessage(dwFlags, 0, lnErr, 0, @lpBuffer, 0,0)
	IF lnLength <> 0
		lpResult = REPLI(Chr(0), 500)
		= CopyMemory (@lpResult, lpBuffer, lnLength)
		RETURN STRTRAN(LEFT(lpResult, lnLength), Chr(13)+Chr(10), "")
	ELSE
		RETURN "[]"
	ENDIF  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CopyMemory](../libraries/kernel32/CopyMemory.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[FormatMessage](../libraries/kernel32/FormatMessage.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
In Windows all input/output ports are presented as files, so work with ports is performed through file functions like CreateFile, CloseHandle, ReadFile, ReadFileEx, WriteFile and WriteFileEx.   
  
Code sample [Get the owner of an NTFS file](sample_433.md) works with serial ports as well as with regular files.  
  

Check VB example [Using CreateFile to Determine Available COM Ports](http://vbnet.mvps.org/index.html?code/system/comtestapi.htm) on [VBNet](http://vbnet.mvps.org).  
  
***  

