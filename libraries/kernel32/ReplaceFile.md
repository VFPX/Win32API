<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ReplaceFile
Group: File Management - Library: kernel32    
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
```txt  
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
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
In VFP use the ASCII version for this function, unless you specifically convert the first three input parameters (file names) into Unicode strings.  
  
***  

