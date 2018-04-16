[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeMoveFile
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function renames an existing file or a directory � including all its children.
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
lpExistingFileName 
[in] Long pointer to a null-terminated string that names an existing file or directory. 

lpNewFileName 
[in] Long pointer to a null-terminated string that specifies the new name of a file or directory.  
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
The new name must not already exist. A new file may be on a different file system or drive. A new directory must be on the same drive. You must specify the complete directory path.  
  
Note that the concept of a current directory <Em>does not exist</Em> in Windows CE.   
  
See also: [CeCopyFile](CeCopyFile.md) and [CeDeleteFile](CeDeleteFile.md) functions.  
  
***  

