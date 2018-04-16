[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDrawImageI
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
graphics
[in] Pointer to a Graphics object.

image
[in] Pointer to an Image object that specifies the image to be drawn. 

x
[in] Integer that specifies the x-coordinate of the upper-left corner of the rendered image. 

y
[in] Integer that specifies the y-coordinate of the upper-left corner of the rendered image.   
***  


## Return value:
If succeeds, it returns Ok, which is an element of the Status enumeration.  
***  


## Comments:
This function can be used for cropping images:  
* load a source image  
* create a blank image the size of the valid part of the source image  
* use negative x and y offsets to draw the source image on the target image  
  
***  

