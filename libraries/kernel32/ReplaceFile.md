[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ReplaceFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Replaces one file with another file, with the option of creating a backup copy of the original file. 
***  


## Declaration:
```foxpro  
BOOL WINAPI ReplaceFile(
  __in        LPCTSTR lpReplacedFileName,
  __in        LPCTSTR lpReplacementFileName,
  __in_opt    LPCTSTR lpBackupFileName,
  __in        DWORD dwReplaceFlags,
  __reserved  LPVOID lpExclude,
  __reserved  LPVOID lpReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReplaceFileA IN kernel32;
	STRING lpReplacedFileName,;
	STRING lpReplacementFileName,;
	STRING lpBackupFileName,;
	LONG dwReplaceFlags,;
	INTEGER lpExclude,;
	INTEGER lpReserved  
```  
***  


## Parameters:
lpReplacedFileName [in] 
The name of the file to be replaced.

lpReplacementFileName [in] 
The name of the file that will replace the lpReplacedFileName file.

lpBackupFileName [in, optional] 
The name of the file that will serve as a backup copy of the lpReplacedFileName file. If this parameter is NULL, no backup file is created.

dwReplaceFlags [in] 
The replacement options.

lpExclude 
Reserved for future use.

lpReserved 
Reserved for future use.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
In VFP use the ASCII version for this function, unless you specifically convert the first three input parameters (file names) into Unicode strings.  
  
***  

