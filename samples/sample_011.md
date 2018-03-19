[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the DeleteFile

## Before you begin:
See also:

* [Deleting file into the Recycle Bin](sample_321.md)  
* [Displaying standard progress dialog box when copying files](sample_508.md)  

  
***  


## Code:
```foxpro  
#DEFINE CREATE_ALWAYS                  2
#DEFINE FILE_ATTRIBUTE_NORMAL        128

DECLARE INTEGER DeleteFile IN kernel32;
	STRING lpFileName

DECLARE INTEGER CreateFile IN kernel32;
	STRING  lpFileName,;
	INTEGER dwDesiredAccess,;
	INTEGER dwShareMode,;
	INTEGER lpSecurityAttributes,;
	INTEGER dwCreationDisposition,;
	INTEGER dwFlagsAndAttributes,;
	INTEGER hTemplateFile

DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

LOCAL lpFileName
lpFileName = "C:\Temp\mytest.txt"

hResult = CreateFile (lpFileName, 0, 0, 0,;
	CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0)

? "File handle returned:", hResult
= CloseHandle (hResult)
= DeleteFile (lpFileName)  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[DeleteFile](../libraries/kernel32/DeleteFile.md)  

## Comment:
Windows 95/98/Me: The DeleteFile function deletes a file even if it is open for normal I/O or as a memory-mapped file. To prevent loss of data, close files before attempting to delete them.  
  
***  

