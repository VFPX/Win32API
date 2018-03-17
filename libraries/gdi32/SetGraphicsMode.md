<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetGraphicsMode
Group: Coordinate Space and Transformation - Library: gdi32    
***  


#### Sets the graphics mode for the specified device context.
***  


## Declaration:
```foxpro  
int SetGraphicsMode(
	HDC hdc,    // handle to device context
	int iMode   // graphics mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetGraphicsMode IN gdi32;
	INTEGER hdc, INTEGER iMode
  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context.

iMode
[in] Specifies the graphics mode.  
```  
***  


## Return value:
If the function succeeds, the return value is the old graphics mode.  
***  


## Comments:
See also: GetGraphicsMode   
  
***  

