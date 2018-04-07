[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateHICONFromBitmap
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates an icon from this Bitmap object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateHICONFromBitmap(
	GpBitmap* bitmap,;
	HICON* hbmReturn
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateHICONFromBitmap IN gdiplus;
	INTEGER @hbitmap,;
	INTEGER @hbmReturn  
```  
***  


## Parameters:
hbitmap
[in] Handle to a GDI bitmap. 

hbmReturn
[out] Handle to a Microsoft Windows Graphics Device Interface (GDI) icon.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: [GdipCreateBitmapFromHICON](../gdiplus/GdipCreateBitmapFromHICON.md), [GdipCreateBitmapFromHBITMAP](../gdiplus/GdipCreateBitmapFromHBITMAP.md).  
  
***  

