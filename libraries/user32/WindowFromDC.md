<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WindowFromDC
Group: Painting and Drawing - Library: user32    
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
```txt  
hDC
[in] Handle to the device context from which a handle to the associated window is to be retrieved.  
```  
***  


## Return value:
The return value is a handle to the window associated with the specified DC. If no window is associated with the specified DC, the return value is NULL.   
***  

