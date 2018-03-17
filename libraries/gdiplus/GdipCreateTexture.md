<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateTexture
Group: GDI+ Brush - Library: gdiplus    
***  


#### Creates a brush that contains an Image object that is used for the fill.
***  


## Code examples:
[Adding a background image to VFP report (VFP9, ReportListener)](../../samples/sample_562.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateTexture(
	GpImage *image,
	GpWrapMode wrapmode,
	GpTexture **texture
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateTexture IN gdiplus;
	INTEGER img,;
	LONG wrapmode,;
	INTEGER @texture  
```  
***  


## Parameters:
```txt  
image
[in] Handle to Image Object

wrapmode
[in] Element of the WrapMode enumeration that specifies how repeated copies of an image are used to tile an area when it is painted with this texture brush.

texture
[out] Handle of the brush object.
  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: GdipCreateSolidFill, GdipDeleteBrush, GdipFillRectangle   
  
***  

