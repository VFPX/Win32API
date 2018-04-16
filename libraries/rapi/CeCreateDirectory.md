[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeCreateDirectory
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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
lpPathName 
[in] Long pointer to a null-terminated string that specifies the path of the directory to be created. 

lpSecurityAttributes 
[in] Ignored; set to NULL.   
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
See also: [CeRemoveDirectory](CeRemoveDirectory.md) function.  
  
***  

