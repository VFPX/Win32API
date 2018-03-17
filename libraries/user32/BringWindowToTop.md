<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : BringWindowToTop
Group: Window - Library: user32    
***  


#### Brings the specified window to the top of the Z order. If the window is a top-level window, it is activated. If the window is a child window, the top-level parent window associated with the child window is activated.
***  


## Declaration:
```foxpro  
BOOL WINAPI BringWindowToTop(
  _In_  HWND hWnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER BringWindowToTop IN user32;
	INTEGER hWindow  
```  
***  


## Parameters:
```txt  
hWnd [in]
Type: HWND
A handle to the window to bring to the top of the Z order.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Use the BringWindowToTop function to uncover any window that is partially or completely obscured by other windows.  
  
Calling this function is similar to calling the SetWindowPos function to change a window"s position in the Z order. BringWindowToTop does not make a window a top-level window.  
  
***  

