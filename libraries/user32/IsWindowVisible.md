[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsWindowVisible
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The IsWindowVisible function retrieves the visibility state of the specified window
***  


## Code examples:
[Listing child windows for the Windows desktop](../../samples/sample_027.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Minimizing all running applications](../../samples/sample_244.md)  

## Declaration:
```foxpro  
BOOL IsWindowVisible(
    HWND  hWnd 	// handle of window
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsWindowVisible IN user32 INTEGER hwnd  
```  
***  


## Parameters:
hWnd
Identifies the window  
***  


## Return value:
If the specified window is visible on the screen (has the WS_VISIBLE style), the return value is TRUE  
***  

