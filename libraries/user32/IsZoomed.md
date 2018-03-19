
## Function name : IsZoomed
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
hWnd
[in] Handle to the window to test.   
***  


## Return value:
If the window is zoomed, the return value is nonzero.  
***  


## Comments:
See the IsIconic function.  
  
***  

