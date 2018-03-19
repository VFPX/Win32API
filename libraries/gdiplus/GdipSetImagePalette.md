
## Function name : GdipSetImagePalette
Group: GDI+ Image - Library: gdiplus    
***  


#### Sets the color palette of this Image object.

***  


## Code examples:
[Displaying the color palette stored in an image file](../../samples/sample_529.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetImagePalette(
	GpImage *image,
	GDIPCONST ColorPalette *palette
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetImagePalette IN gdiplus;
	INTEGER img,;
	STRING @imgpalette  
```  
***  


## Parameters:
img
[in] Handle to Image Object

palette
[in] Pointer to a ColorPalette structure that specifies the palette.  
***  


## Return value:
Returns GpStatus value, 0 means success.   
***  


## Comments:
See also: GdipGetImagePalette   
  
***  

