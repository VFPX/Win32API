
## Function name : GetShellWindow
Group: Window - Library: user32    
***  


#### The GetShellWindow function returns a handle to the Shell"s desktop window.
***  


## Declaration:
```foxpro  
HWND GetShellWindow(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetShellWindow IN user32  
```  
***  


## Parameters:
This function has no input parameters.  
***  


## Return value:
The return value is the handle of the Shell"s desktop window. If no Shell process is present, the return value is NULL.  
***  


## Comments:
My guess: in many cases this function returns result very close (but not identical) to the GetDesktopWindow function.  
  
***  

