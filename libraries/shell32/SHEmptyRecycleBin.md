[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHEmptyRecycleBin
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Empties the Recycle Bin on the specified drive. 
***  


## Code examples:
[How to empty the Recycle Bin](../../samples/sample_301.md)  

## Declaration:
```foxpro  
HRESULT SHEmptyRecycleBin(
	HWND hwnd,
	LPCTSTR pszRootPath,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHEmptyRecycleBin IN shell32;
	INTEGER hwnd,;
	STRING  pszRootPath,;
	LONG    dwFlags  
```  
***  


## Parameters:
hwnd
Handle to the parent window of any dialog boxes that might be displayed during the operation. 

pszRootPath
Address of a null-terminated string of maximum length MAX_PATH that contains the path of the root drive on which the Recycle Bin is located. 

dwFlags
One or more of the predefined values.  
***  


## Return value:
Returns S_OK (0) if successful, or an OLE-defined error value otherwise.  
***  

