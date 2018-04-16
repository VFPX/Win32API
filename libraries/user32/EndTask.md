[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EndTask
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The EndTask function is called to forcibly close a specified window.
***  


## Declaration:
```foxpro  
BOOL EndTask(
	HWND hWnd,
	BOOL fShutDown,
	BOOL fForce
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EndTask IN user32;
	INTEGER hWindow,;
	INTEGER fShutDown,;
	INTEGER fForce
  
```  
***  


## Parameters:
hWnd
[in] Handle to the window to be closed. 

fShutDown
[in] Ignored. Must be FALSE. 

fForce
[in] A TRUE for this parameter will force the destruction of the window if an initial attempt fails to gently close the window using WM_CLOSE. With a FALSE for this parameter, only the close with WM_CLOSE is attempted.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Upon receiving WM_CLOSE, by default, the DefWindowProc function calls the DestroyWindow function to destroy the window.  
  
The following code is most likely invoked when the EndTask called with <Em>fForce=False</Em> :  
  
```foxpro
#DEFINE WM_CLOSE 0x0010  
DECLARE INTEGER GetActiveWindow IN user32  
DECLARE INTEGER PostMessage IN user32;  
	INTEGER hWindow, INTEGER Msg,;  
	INTEGER wParam, INTEGER lParam  
  
= PostMessage(GetActiveWindow(), WM_CLOSE, 0,0)
```
See also: [IsWindow](../user32/IsWindow.md).  
  
***  

