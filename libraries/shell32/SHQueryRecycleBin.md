[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHQueryRecycleBin
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Retrieves the size of the Recycle Bin, and the number of items in it, on the specified drive. 
***  


## Code examples:
[How to retrieve the number of objects stored in the Recycle Bin](../../samples/sample_302.md)  

## Declaration:
```foxpro  
HRESULT SHQueryRecycleBin(
	LPCTSTR pszRootPath,
	LPSHQUERYRBINFO pSHQueryRBInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHQueryRecycleBin IN shell32;
	STRING   pszRootPath,;
	STRING @ pSHQueryRBInfo  
```  
***  


## Parameters:
pszRootPath
Address of a null-terminated string of maximum length MAX_PATH to contain the path of the root drive on which the Recycle Bin is located.

pSHQueryRBInfo
Address of a SHQUERYRBINFO structure that receives the Recycle Bin information.   
***  


## Return value:
Returns S_OK (0) if successful, or an OLE-defined error value otherwise.   
***  

