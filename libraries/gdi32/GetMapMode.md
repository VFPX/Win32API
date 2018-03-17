<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetMapMode
Group: Coordinate Space and Transformation - Library: gdi32    
***  


#### Retrieves the current mapping mode.
***  


## Declaration:
```foxpro  
int GetMapMode(
	HDC hdc   // handle to device context
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMapMode IN gdi32;
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
If the function succeeds, the return value specifies the mapping mode.  
***  


## Comments:
See also: SetMapMode   
  
***  

