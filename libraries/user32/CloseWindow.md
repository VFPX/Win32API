[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CloseWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The CloseWindow function minimizes (but does not destroy) the specified window.
***  


## Code examples:
[Minimizing all running applications](../../samples/sample_244.md)  

## Declaration:
```foxpro  
BOOL CloseWindow(
  HWND hWnd   // handle to window to minimize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CloseWindow IN user32;
	INTEGER hWnd  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window to be minimized.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
It is an example of misleading name. To destroy a window, an application must use the DestroyWindow function.   
  
***  

