[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating a file, then moving it to another destination

## Before you begin:
See also:

* [Displaying standard progress dialog box when copying files](sample_508.md)  

  
***  


## Code:
```foxpro  
#DEFINE CREATE_ALWAYS 2
#DEFINE FILE_ATTRIBUTE_NORMAL 128

DO declare

lpFileName = "C:\Temp\mytest.txt"
lpNewFileName = "C:\Temp\mytest1.txt"

hFile = CreateFile(lpFileName, 0, 0, 0,;
	CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0)

? "File handle returned:", hFile
= CloseHandle (hFile)
= MoveFile(lpFileName, lpNewFileName)

PROCEDURE declare
	DECLARE INTEGER MoveFile IN kernel32;
		STRING lpExistingFileName, STRING lpNewFileName

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
		INTEGER dwShareMode, INTEGER lpSecurityAttributes,;
		INTEGER dwCreationDisposition,;
		INTEGER dwFlagsAndAttributes, INTEGER hTemplateFile

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[MoveFile](../libraries/kernel32/MoveFile.md)  
