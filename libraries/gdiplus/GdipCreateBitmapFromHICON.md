[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateBitmapFromHICON
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a Bitmap object based on a handle to an icon.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateBitmapFromHICON(
	HICON hicon,
	GpBitmap** bitmap
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateBitmapFromHICON IN gdiplus;
	INTEGER hicon,;
	INTEGER @hbitmap
  
```  
***  


## Parameters:
hicon
[in] Handle to a Microsoft Windows Graphics Device Interface (GDI) icon.

bitmap
[out] Handle to the GDI+ bitmap object.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: [GdipCreateBitmapFromHBITMAP](../gdiplus/GdipCreateBitmapFromHBITMAP.md), [GdipCreateHICONFromBitmap](../gdiplus/GdipCreateHICONFromBitmap.md).  
  
***  

