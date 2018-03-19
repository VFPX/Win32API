[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the CreateFile

## Code:
```foxpro  
#DEFINE CREATE_NEW 1
#DEFINE CREATE_ALWAYS 2
#DEFINE OPEN_EXISTING 3

#DEFINE FILE_ATTRIBUTE_NORMAL 128

#DEFINE GENERIC_READ   0x80000000
#DEFINE GENERIC_WRITE  0x40000000
#DEFINE GENERIC_ALL    0x10000000
#DEFINE MAXIMUM_ALLOWED 0x02000000
#DEFINE STANDARD_RIGHTS_ALL 0x001F0000

#DEFINE FILE_SHARE_READ 1
#DEFINE FILE_SHARE_WRITE 2
#DEFINE FILE_SHARE_DELETE 4
#DEFINE INVALID_HANDLE_VALUE -1

DO declare

hFile = CreateFile("c:\temp\myfile.txt",;
			GENERIC_WRITE,;
			FILE_SHARE_WRITE,;
			0,;
			CREATE_ALWAYS,;
			FILE_ATTRIBUTE_NORMAL,;
			0)

IF hFile <> INVALID_HANDLE_VALUE
	? "File handle returned: ", hFile
	= CloseHandle (hFile)
ELSE
	*  2 = ERROR_FILE_NOT_FOUND
	*  3 = ERROR_PATH_NOT_FOUND
	* 13 = ERROR_INVALID_DATA
	* 87 = ERROR_INVALID_PARAMETER
	? "Error code returned:", GetLastError()
ENDIF
* end of main

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
		INTEGER dwShareMode, INTEGER lpSecurityAttr,;
		INTEGER dwCreationDisp, INTEGER dwFlagsAndAttrs,;
		INTEGER hTemplateFile  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
This example creates a new file and closes it.  
  
***  

