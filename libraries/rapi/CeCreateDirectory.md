<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeCreateDirectory
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function creates a new directory.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
BOOL CeCreateDirectory(
  LPCWSTR lpPathName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeCreateDirectory IN rapi;
	STRING  lpPathName,;
	INTEGER lpSecurityAttributes
  
```  
***  


## Parameters:
```txt  
lpPathName
[in] Long pointer to a null-terminated string that specifies the path of the directory to be created.

lpSecurityAttributes
[in] Ignored; set to NULL.  
```  
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
See also CeRemoveDirectory function.  
  
***  

