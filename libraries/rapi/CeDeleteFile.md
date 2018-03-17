<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeDeleteFile
Group: Remote Application Programming (RAPI) - Library: rapi    
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
```txt  
lpFileName
[in] Long pointer to a null-terminated string that specifies the file to be deleted.  
```  
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
See also CeMoveFile and CeCopyFile functions.  
  
***  

