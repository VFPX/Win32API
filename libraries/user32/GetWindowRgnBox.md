<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetWindowRgnBox
Group: Painting and Drawing - Library: user32    
***  


#### Retrieves the dimensions of the tightest bounding rectangle for the window region of a window. 
***  


## Declaration:
```foxpro  
int GetWindowRgnBox(
	HWND hWnd, // handle to window
	LPRECT lprc   // rectangle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowRgnBox IN user32;
	INTEGER hWindow,;
	STRING @lprc  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the window.

lprc
[out] Pointer to a RECT structure that receives the rectangle dimensions, in device units relative to the upper-left corner of the window.  
```  
***  


## Return value:
The return value specifies the type of the region that the function obtains.  
***  


## Comments:
The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region.   
  
***  

