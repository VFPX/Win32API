<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateHICONFromBitmap
Group: GDI+ Bitmap - Library: gdiplus    
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
```txt  
hbitmap
[in] Handle to a GDI bitmap.

hbmReturn
[out] Handle to a Microsoft Windows Graphics Device Interface (GDI) icon.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: GdipCreateBitmapFromHICON, GdipCreateBitmapFromHBITMAP.  
  
***  

