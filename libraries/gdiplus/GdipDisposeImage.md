<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDisposeImage
Group: GDI+ Image - Library: gdiplus    
***  


#### The GdipDisposeImage releases an Image object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[Adding a background image to VFP report (VFP9, ReportListener)](../../samples/sample_562.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDisposeImage(
	GpImage *image
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDisposeImage IN gdiplus;
	INTEGER img  
```  
***  


## Parameters:
```txt  
img
[in]  Identifies the Image created by GdipLoadImageFromFile, GdipLoadImageFromStream and other Image constructors.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

