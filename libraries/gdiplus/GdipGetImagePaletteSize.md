<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetImagePaletteSize
Group: GDI+ Image - Library: gdiplus    
***  


#### Gets the size, in bytes, of the color palette of this Image object.

***  


## Code examples:
[Displaying the color palette stored in an image file](../../samples/sample_529.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImagePaletteSize(
	GpImage *image,
	INT *size
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImagePaletteSize IN gdiplus;
	INTEGER img,;
	INTEGER @palettesize  
```  
***  


## Parameters:
```txt  
image
[in] Handle to Image Object

size
[out] Size of the color palette of this Image object, in bytes.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success. 
  
***  

