<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetWorldTransform
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Sets the world transformation of this Graphics object.

***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetWorldTransform(
	GpGraphics *graphics,
	GpMatrix *matrix
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetWorldTransform IN gdiplus;
	INTEGER graphics,;
	INTEGER matrix
  
```  
***  


## Parameters:
```txt  
graphics
[in] Handle to the Graphics object.

matrix
[in] Handle to a Matrix object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.   
***  

