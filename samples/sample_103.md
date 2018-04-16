[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Changing file attributes

## Code:
```foxpro  
LPARAMETERS  lpFileName

#DEFINE FILE_ATTRIBUTE_READONLY       1
#DEFINE FILE_ATTRIBUTE_HIDDEN         2
#DEFINE FILE_ATTRIBUTE_SYSTEM         4
#DEFINE FILE_ATTRIBUTE_DIRECTORY     16
#DEFINE FILE_ATTRIBUTE_ARCHIVE       32
#DEFINE FILE_ATTRIBUTE_NORMAL       128
#DEFINE FILE_ATTRIBUTE_TEMPORARY    512
#DEFINE FILE_ATTRIBUTE_COMPRESSED  2048

DECLARE SHORT SetFileAttributes IN kernel32;
	STRING lpFileName, INTEGER dwFileAttributes

DECLARE INTEGER GetFileAttributes IN kernel32 STRING lpFileName

* read current attributes for this file
dwFileAttributes = GetFileAttributes (lpFileName)

IF dwFileAttributes = -1
* the file does not exist
	RETURN
ENDIF

IF dwFileAttributes > 0
	* read-only attribute to be set
	dwFileAttributes = BitOr(dwFileAttributes, FILE_ATTRIBUTE_READONLY)
		
	* archive attribute to be removed
	IF BitAnd(dwFileAttributes, FILE_ATTRIBUTE_ARCHIVE) = FILE_ATTRIBUTE_ARCHIVE
		dwFileAttributes = dwFileAttributes - FILE_ATTRIBUTE_ARCHIVE
	ENDIF

	* setting selected attributes
	= SetFileAttributes (lpFileName, dwFileAttributes)
ENDIF  
```  
***  


## Listed functions:
[GetFileAttributes](../libraries/kernel32/GetFileAttributes.md)  
[SetFileAttributes](../libraries/kernel32/SetFileAttributes.md)  

## Comment:
Pass a file name to this procedure. This code sets read-only and clears archive attributes for the selected file.  
  
DOS command ATTRIB can be used for the same purpose:  
```dos
ATTRIB -R c:\mydir\*.* /S
```

***  

