<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IsIconic
Group: Window - Library: user32    
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
```txt  
hWnd
[in] Handle to the window to test.  
```  
***  


## Return value:
If the window is iconic, the return value is nonzero.  
***  


## Comments:
See the IsZoomed function.  
  
***  

