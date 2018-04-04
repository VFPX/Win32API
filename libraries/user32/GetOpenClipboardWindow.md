[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetOpenClipboardWindow
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the handle to the window that currently has the clipboard open.
***  


## Declaration:
```foxpro  
HWND WINAPI GetOpenClipboardWindow(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetOpenClipboardWindow IN user32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
If the function succeeds, the return value is the handle to the window that has the clipboard open. If no window has the clipboard open, the return value is NULL.  
***  


## Comments:
If an application or DLL specifies a NULL window handle when calling the OpenClipboard function, the clipboard is opened but is not associated with a window. In such a case, GetOpenClipboardWindow returns NULL.  
  
***  

