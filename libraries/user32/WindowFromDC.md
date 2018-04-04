[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WindowFromDC
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Returns a handle to the window associated with the specified display device context (DC).

***  


## Code examples:
[Transparent Menu Class (requires VFP9)](../../samples/sample_496.md)  

## Declaration:
```foxpro  
HWND WindowFromDC(
	HDC hDC   // handle to device context
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WindowFromDC IN user32;
	INTEGER hDC  
```  
***  


## Parameters:
hDC 
[in] Handle to the device context from which a handle to the associated window is to be retrieved.   
***  


## Return value:
The return value is a handle to the window associated with the specified DC. If no window is associated with the specified DC, the return value is NULL.   
***  

