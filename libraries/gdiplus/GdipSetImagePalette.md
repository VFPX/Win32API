<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetImagePalette
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
```txt  
img
[in] Handle to Image Object

palette
[in] Pointer to a ColorPalette structure that specifies the palette.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.   
***  


## Comments:
See also: GdipGetImagePalette   
  
***  

