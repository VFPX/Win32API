<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetImagePalette
Group: GDI+ Image - Library: gdiplus    
***  


#### Gets the color palette of this Image object.
***  


## Code examples:
[Displaying the color palette stored in an image file](../../samples/sample_529.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImagePalette(
	GpImage *image,
	ColorPalette *palette,
	INT size
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImagePalette IN gdiplus;
	INTEGER img,;
	STRING @imgpalette,;
	INTEGER palettesize
  
```  
***  


## Parameters:
```txt  
img
[in] Handle to Image Object

palette
[out] Pointer to a ColorPalette structure that receives the palette.

size
[in] Integer that specifies the size, in bytes, of the palette.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
Call GdipGetImagePaletteSize function to determine the size.  
  
See also: GdipSetImagePalette   
  
***  

