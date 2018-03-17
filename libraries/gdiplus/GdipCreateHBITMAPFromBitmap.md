<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateHBITMAPFromBitmap
Group: GDI+ Bitmap - Library: gdiplus    
***  


#### Creates a Microsoft® Windows® Graphics Device Interface (GDI) bitmap from this GDI+ Bitmap handle.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateHBITMAPFromBitmap(
	GpBitmap* bitmap,
	HBITMAP* hbmReturn,
	ARGB background
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateHBITMAPFromBitmap IN gdiplus;
	INTEGER   bitmap,;
	INTEGER @ hbmReturn,;
	INTEGER   background
  
```  
***  


## Parameters:
```txt  
bitmap
[in] Handle to the GDI+ bitmap object.

hbmReturn
[out] Pointer to an HBITMAP that receives a handle to the GDI bitmap.

colorBackground
[in] Reference to a Color object that specifies the background color.  
```  
***  


## Return value:
Returns 0 on success.  
***  

