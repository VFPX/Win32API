<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetMapMode
Group: Coordinate Space and Transformation - Library: gdi32    
***  


#### Sets the mapping mode of the specified device context.
***  


## Declaration:
```foxpro  
int SetMapMode(
	HDC hdc,        // handle to device context
	int fnMapMode   // new mapping mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetMapMode IN gdi32;
	INTEGER hdc, INTEGER fnMapMode
  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context.

fnMapMode
[in] Specifies the new mapping mode.  
```  
***  


## Return value:
If the function succeeds, the return value identifies the previous mapping mode.  
***  


## Comments:
The mapping mode defines the unit of measure used to transform page-space units into device-space units, and also defines the orientation of the device"s x and y axes.   
  
See also: GetMapMode   
  
***  

