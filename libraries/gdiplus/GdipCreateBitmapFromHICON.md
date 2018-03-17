<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateBitmapFromHICON
Group: GDI+ Bitmap - Library: gdiplus    
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
```txt  
hicon
[in] Handle to a Microsoft Windows Graphics Device Interface (GDI) icon.

bitmap
[out] Handle to the GDI+ bitmap object.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
See also: GdipCreateBitmapFromHBITMAP, GdipCreateHICONFromBitmap.  
  
***  

