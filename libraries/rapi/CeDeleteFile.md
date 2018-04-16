[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeDeleteFile
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function deletes an existing file from the object store.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
BOOL CeDeleteFile(
	LPCWSTR lpFileName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeDeleteFile IN rapi;
	STRING lpFileName  
```  
***  


## Parameters:
lpFileName 
[in] Long pointer to a null-terminated string that specifies the file to be deleted.   
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
See also: [CeMoveFile](CeMoveFile.md) and [CeCopyFile](CeCopyFile.md) functions.  
  
***  

