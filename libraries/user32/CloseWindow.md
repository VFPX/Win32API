<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CloseWindow
Group: Window - Library: user32    
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
```txt  
hWnd
[in] Handle to the window to be minimized.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
It is an example of misleading name. To destroy a window, an application must use the DestroyWindow function.   
  
***  

