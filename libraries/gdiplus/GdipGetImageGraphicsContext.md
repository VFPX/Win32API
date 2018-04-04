[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageGraphicsContext
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
image
[in] Pointer to an Image object that will be associated with the new Graphics object.   
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The technique of constructing a Graphics object based on an image works only for certain image formats. For example, you cannot construct a Graphics object based on an image that has a color depth of 4 bits per pixel.  
  
***  

