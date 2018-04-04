[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipLoadImageFromFile
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates an Image object based on a file.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  
[Adding a background image to VFP report (VFP9, ReportListener)](../../samples/sample_562.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipLoadImageFromFile(
	GDIPCONST WCHAR* filename,
	GpImage **image
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipLoadImageFromFile IN gdiplus;
	STRING    filename,;
	INTEGER @ img  
```  
***  


## Parameters:
filename
[in] Pointer to a wide-character string that specifies the name of the file.

img
[out] Image handle.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

