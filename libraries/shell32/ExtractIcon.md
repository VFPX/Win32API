[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ExtractIcon
Group: [Icon](../../functions_group.md#Icon)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Retrieves a handle to an icon from the specified executable file, dynamic-link library (DLL), or icon file.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[How to view icons stored in executable files (Icon Viewer)](../../samples/sample_113.md)  
[GDI+: Storing DLL icon resources in image files](../../samples/sample_501.md)  

## Declaration:
```foxpro  
HICON ExtractIcon(
  HINSTANCE hInst,          // instance handle
  LPCTSTR lpszExeFileName,  // file name
  UINT nIconIndex           // icon index
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ExtractIcon IN shell32;
	INTEGER hInst,;
	STRING  lpszExeFileName,;
	INTEGER lpiIcon  
```  
***  


## Parameters:
hInst 
[in] Handle to the instance of the application calling the function. 

lpszExeFileName 
[in] Pointer to a null-terminated string specifying the name of an executable file, DLL, or icon file. 

nIconIndex 
[in] Specifies the zero-based index of the icon to retrieve.  
***  


## Return value:
The return value is a handle to an icon, otherwise it is NULL.  
***  


## Comments:
You must destroy the icon handle returned by ExtractIcon by calling the DestroyIcon function.  
  
See also: [ExtractAssociatedIcon](../shell32/ExtractAssociatedIcon.md), [GetIconInfo](../user32/GetIconInfo.md), [SHGetStockIconInfo](../shell32/SHGetStockIconInfo.md).  
  
***  

