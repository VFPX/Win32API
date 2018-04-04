[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeCopyFile
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function copies an existing file to a new file.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
BOOL CeCopyFile(
  LPCWSTR lpExistingFileName,
  LPCWSTR lpNewFileName,
  BOOL bFailIfExists
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeCopyFile IN rapi;
	STRING  lpExistingFileName,;
	STRING  lpNewFileName,;
	INTEGER bFailIfExists
  
```  
***  


## Parameters:
lpExistingFileName 
[in] Long pointer to a null-terminated string that specifies the name of an existing file. 

lpNewFileName 
[in] Long pointer to a null-terminated string that specifies the name of the new file. 

bFailIfExists 
[in] Boolean value that specifies how this operation is to proceed if a file of the same name as that indicated by lpNewFileName already exists.   
***  


## Return value:
Nonzero indicates success.   
***  


## Comments:
See also CeMoveFile and CeDeleteFile functions.  
  
***  

