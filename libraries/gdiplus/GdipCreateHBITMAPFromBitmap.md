[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateHBITMAPFromBitmap
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a Microsoft&reg; Windows&reg; Graphics Device Interface (GDI) bitmap from this GDI+ Bitmap handle.

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
bitmap
[in] Handle to the GDI+ bitmap object.

hbmReturn
[out] Pointer to an HBITMAP that receives a handle to the GDI bitmap. 

colorBackground
[in] Reference to a Color object that specifies the background color.  
***  


## Return value:
Returns 0 on success.  
***  

