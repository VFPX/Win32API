<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ReleaseCapture
Group: Mouse Input - Library: user32    
***  


#### Releases the mouse capture from a window in the current thread and restores normal mouse input processing. A window that has captured the mouse receives all mouse input, regardless of the position of the cursor, except when a mouse button is clicked while the cursor hot spot is in the window of another thread.
***  


## Code examples:
[Creating irregularly shaped FoxPro form using transparency color key](../../samples/sample_033.md)  
[Round FoxPro form](../../samples/sample_143.md)  
[How to drag a Form not using its Titlebar or Caption](../../samples/sample_195.md)  
[Setting the mouse capture to the specified window](../../samples/sample_282.md)  
[How to draw custom Window Caption on FoxPro form](../../samples/sample_499.md)  
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  

## Declaration:
```foxpro  
BOOL ReleaseCapture(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReleaseCapture IN user32  
```  
***  


## Parameters:
```txt  
This function has no parameters.   
```  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
An application calls this function after calling the SetCapture function.   
  
***  

