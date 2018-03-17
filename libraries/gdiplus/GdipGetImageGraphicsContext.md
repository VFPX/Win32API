<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetImageGraphicsContext
Group: GDI+ Image - Library: gdiplus    
***  


#### Creates a Graphics object that is associated with an Image object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImageGraphicsContext(
	GpImage *image,
	GpGraphics **graphics
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageGraphicsContext IN gdiplus;
	INTEGER   img,;
	INTEGER @ graphics
  
```  
***  


## Parameters:
```txt  
image
[in] Pointer to an Image object that will be associated with the new Graphics object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The technique of constructing a Graphics object based on an image works only for certain image formats. For example, you cannot construct a Graphics object based on an image that has a color depth of 4 bits per pixel.  
  
***  

