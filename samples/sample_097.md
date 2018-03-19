[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to test file attributes (key method for FileExists and DirectoryExists routines)

## Code:
```foxpro  
#DEFINE FILE_ATTRIBUTE_READONLY       1
#DEFINE FILE_ATTRIBUTE_HIDDEN         2
#DEFINE FILE_ATTRIBUTE_SYSTEM         4
#DEFINE FILE_ATTRIBUTE_DIRECTORY     16
#DEFINE FILE_ATTRIBUTE_ARCHIVE       32
#DEFINE FILE_ATTRIBUTE_NORMAL       128
#DEFINE FILE_ATTRIBUTE_TEMPORARY    512
#DEFINE FILE_ATTRIBUTE_COMPRESSED  2048

    DECLARE INTEGER GetLastError IN kernel32
    DECLARE INTEGER GetFileAttributes IN kernel32 STRING lpFileName

    * both notations are acceptable
    lpFileName = "c:\Program Files\Microsoft Office"
*    lpFileName = "//thatbloke/c/windows/system"

    lnAttributes = GetFileAttributes (lpFileName)
    IF lnAttributes >= 0
    ? "File name: ", lpFileName
    ? "Attributes: ", lnAttributes

    = displayFlag (lnAttributes, FILE_ATTRIBUTE_READONLY, "Read-only: ")
    = displayFlag (lnAttributes, FILE_ATTRIBUTE_HIDDEN, "Hidden: ")
    = displayFlag (lnAttributes, FILE_ATTRIBUTE_SYSTEM, "System: ")
    = displayFlag (lnAttributes, FILE_ATTRIBUTE_DIRECTORY, "Directory: ")
    = displayFlag (lnAttributes, FILE_ATTRIBUTE_ARCHIVE, "Archive: ")
    = displayFlag (lnAttributes, FILE_ATTRIBUTE_NORMAL, "Normal: ")
    = displayFlag (lnAttributes, FILE_ATTRIBUTE_TEMPORARY, "Temporary: ")
    = displayFlag (lnAttributes, FILE_ATTRIBUTE_COMPRESSED, "Compressed: ")
    ELSE
        *  2 - The system cannot find the file specified = ERROR_FILE_NOT_FOUND
        *  3 - The system cannot find the path specified = ERROR_PATH_NOT_FOUND
        * 21 - The device is not ready = ERROR_NOT_READY
        ? "Error code: ", GetLastError()
    ENDIF

PROCEDURE  displayFlag (lnFlags, lnMask, lcCaption)
    lcResult = IIF (BitAnd(lnFlags, lnMask) = lnMask, "[x]", "[ ]")
    ? "   ", lcResult, lcCaption
RETURN  
```  
***  


## Listed functions:
[GetFileAttributes](../libraries/kernel32/GetFileAttributes.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
By the way, this routine can very accurately test an access to a directory. Check the DirectoryExists function in your framework.  
  
Not only the directory accessibility, but this function returns ReadOnly status.  
  
***  

