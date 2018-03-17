<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetCapture
Group: Mouse Input - Library: user32    
***  


#### The GetCapture function retrieves a handle to the window (if any) that has captured the mouse. Only one window at a time can capture the mouse; this window receives mouse input whether or not the cursor is within its borders. 
***  


## Code examples:
[Setting the mouse capture to the specified window](../../samples/sample_282.md)  
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  

## Declaration:
```foxpro  
HWND GetCapture(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCapture IN user32  
```  
***  


## Parameters:
```txt  
This function has no parameters.   
```  
***  


## Return value:
The return value is a handle to the capture window associated with the current thread. If no window in the thread has captured the mouse, the return value is NULL.   
***  


## Comments:
The mouse capture.  
  
***  

