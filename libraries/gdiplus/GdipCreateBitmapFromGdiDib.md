[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateBitmapFromGdiDib
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a Bitmap object based on a BITMAPINFO structure and an array of pixel data.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateBitmapFromGdiDib(
	GDIPCONST BITMAPINFO* gdiBitmapInfo,
	VOID* gdiBitmapData,
	GpBitmap** bitmap
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateBitmapFromGdiDib IN gdiplus;
	INTEGER   gdiBitmapInfo,;
	INTEGER   gdiBitmapData,;
	INTEGER @ hBitmap
  
```  
***  


## Parameters:
gdiBitmapInfo
[in] Pointer to a Microsoft Windows Graphics Device Interface (GDI)BITMAPINFO structure.

gdiBitmapData
[in] Pointer to an array of bytes that contains the pixel data.

bitmap
[out] Handle to the GDI+ bitmap object.  
***  


## Return value:
Returns 0 on success or gpstatus value in case of an error.  
***  

