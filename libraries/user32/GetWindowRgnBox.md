[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWindowRgnBox
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
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
hWnd 
[in] Handle to the window. 

lprc 
[out] Pointer to a RECT structure that receives the rectangle dimensions, in device units relative to the upper-left corner of the window.  
***  


## Return value:
The return value specifies the type of the region that the function obtains.  
***  


## Comments:
The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region.   
  
***  

