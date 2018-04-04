[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDisposeImage
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
img
[in]  Identifies the Image created by GdipLoadImageFromFile, GdipLoadImageFromStream and other Image constructors.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

