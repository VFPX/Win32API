<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IsZoomed
Group: Window - Library: user32    
***  


#### The IsZoomed function determines whether a window is maximized. 
***  


## Declaration:
```foxpro  
BOOL IsZoomed(
	HWND hWnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsZoomed IN user32;
	INTEGER hWnd
  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the window to test.  
```  
***  


## Return value:
If the window is zoomed, the return value is nonzero.  
***  


## Comments:
See the IsIconic function.  
  
***  

