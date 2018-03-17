<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SHEmptyRecycleBin
Group: Shell Functions - Library: shell32    
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
```txt  
hwnd
Handle to the parent window of any dialog boxes that might be displayed during the operation.

pszRootPath
Address of a null-terminated string of maximum length MAX_PATH that contains the path of the root drive on which the Recycle Bin is located.

dwFlags
One or more of the predefined values.  
```  
***  


## Return value:
Returns S_OK (0) if successful, or an OLE-defined error value otherwise.  
***  

