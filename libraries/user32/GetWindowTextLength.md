<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetWindowTextLength
Group: Window - Library: user32    
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
```txt  
hWnd
Identifies the window or control  
```  
***  


## Return value:
If the function succeeds, the return value is the length, in characters, of the text  
***  

