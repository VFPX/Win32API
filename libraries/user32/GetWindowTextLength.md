[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWindowTextLength
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetWindowTextLength function retrieves the length, in characters, of the specified window"s title bar text
***  


## Code examples:
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Minimizing all running applications](../../samples/sample_244.md)  

## Declaration:
```foxpro  
int GetWindowTextLength(
    HWND  hWnd 	// handle of window or control with text
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowTextLength IN user32 INTEGER hwnd  
```  
***  


## Parameters:
hWnd
Identifies the window or control  
***  


## Return value:
If the function succeeds, the return value is the length, in characters, of the text  
***  

