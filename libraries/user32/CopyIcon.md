[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CopyIcon
Group: [Icon](../../functions_group.md#Icon)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Copies the specified icon from another module to the current module.
***  


## Code examples:
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  

## Declaration:
```foxpro  
HICON CopyIcon(
	HICON hIcon
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CopyIcon IN user32 INTEGER hIcon  
```  
***  


## Parameters:
hIcon
[in] Handle to the icon to be copied.  
***  


## Return value:
If the function succeeds, the return value is a handle to the duplicate icon.  
***  


## Comments:
The CopyIcon function enables an application or dynamic-link library (DLL) to get its own handle to an icon owned by another module. If the other module is freed, the application icon will still be able to use the icon.   
  
Before closing, an application must call the DestroyIcon function to free any system resources associated with the icon.  
  
See also: [LoadIcon](../user32/LoadIcon.md), [DrawIcon](../user32/DrawIcon.md).  
  
***  

