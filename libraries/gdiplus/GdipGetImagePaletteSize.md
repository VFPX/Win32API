[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImagePaletteSize
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
image
[in] Handle to Image Object

size
[out] Size of the color palette of this Image object, in bytes.  
***  


## Return value:
Returns GpStatus value, 0 means success. 
  
***  

