<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeMoveFile
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function renames an existing file or a directory — including all its children.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
BOOL CeMoveFile(
  LPCWSTR lpExistingFileName,
  LPCWSTR lpNewFileName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeMoveFile IN rapi;
	STRING lpExistingFileName,;
	STRING lpNewFileName
  
```  
***  


## Parameters:
```txt  
lpExistingFileName
[in] Long pointer to a null-terminated string that names an existing file or directory.

lpNewFileName
[in] Long pointer to a null-terminated string that specifies the new name of a file or directory.  
```  
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
The new name must not already exist. A new file may be on a different file system or drive. A new directory must be on the same drive. You must specify the complete directory path.  
  
Note that the concept of a current directory <Em>does not exist</Em> in Windows CE.   
  
See also CeCopyFile and CeDeleteFile functions.  
  
***  

