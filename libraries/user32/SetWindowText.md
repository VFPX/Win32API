[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetWindowText
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Changes the text of the specified window"s title bar (if it has one). If the specified window is a control, the text of the control is changed.
***  


## Code examples:
[Setting properties of the window: caption and user-defined value](../../samples/sample_182.md)  
[How to position the GETPRINTER() dialog](../../samples/sample_482.md)  

## Declaration:
```foxpro  
BOOL SetWindowText(
  HWND hWnd,         // handle to window or control
  LPCTSTR lpString   // title or text
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetWindowText IN user32;
	INTEGER hWnd,;
	STRING  lpString  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window or control whose text is to be changed. 

lpString 
[in] Pointer to a null-terminated string to be used as the new title or control text. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

