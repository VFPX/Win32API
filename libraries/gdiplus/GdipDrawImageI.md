<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDrawImageI
Group: GDI+ Graphics - Library: gdiplus    
***  


#### Draws an image at a specified location.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDrawImageI(
	GpGraphics *graphics,
	GpImage *image,
	INT x,
	INT y
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDrawImageI IN gdiplus;
	INTEGER graphics,;
	INTEGER img,;
	INTEGER x,;
	INTEGER y  
```  
***  


## Parameters:
```txt  
graphics
[in] Pointer to a Graphics object.

image
[in] Pointer to an Image object that specifies the image to be drawn.

x
[in] Integer that specifies the x-coordinate of the upper-left corner of the rendered image.

y
[in] Integer that specifies the y-coordinate of the upper-left corner of the rendered image.  
```  
***  


## Return value:
If succeeds, it returns Ok, which is an element of the Status enumeration.  
***  


## Comments:
This function can be used for cropping images:  
<LI>load a source image  
<LI>create a blank image the size of the valid part of the source image  
<LI>use negative x and y offsets to draw the source image on the target image  
  
***  

