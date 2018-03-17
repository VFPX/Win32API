<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetGraphicsMode
Group: Coordinate Space and Transformation - Library: gdi32    
***  


#### Retrieves the current graphics mode for the specified device context.
***  


## Declaration:
```foxpro  
int GetGraphicsMode(
	HDC hdc   // handle to device context
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetGraphicsMode IN gdi32;
	INTEGER hDC
  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context.  
```  
***  


## Return value:
If the function succeeds, the return value is the current graphics mode.  
***  


## Comments:
An application can set the graphics mode for a device context by calling the SetGraphicsMode function.  
  
***  

