[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsIconic
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The IsIconic function determines whether the specified window is minimized (iconic).
***  


## Code examples:
[Minimizing all running applications](../../samples/sample_244.md)  

## Declaration:
```foxpro  
BOOL IsIconic(
	HWND hWnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsIconic IN user32
	INTEGER hWnd
  
```  
***  


## Parameters:
hWnd
[in] Handle to the window to test.   
***  


## Return value:
If the window is iconic, the return value is nonzero.  
***  


## Comments:
See the [IsZoomed](IsZoomed.md) function.  
  
***  

