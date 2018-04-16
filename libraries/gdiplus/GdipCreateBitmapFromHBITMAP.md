[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateBitmapFromHBITMAP
Group: [GDI+ Bitmap](../../functions_group.md#GDIplus_Bitmap)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a Bitmap object based on a handle to a Windows Microsoft&reg; Windows&reg; Graphics Device Interface (GDI) bitmap and a handle to a GDI palette.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateBitmapFromHBITMAP(
	HBITMAP hbm,
	HPALETTE hpal,
	GpBitmap** bitmap
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateBitmapFromHBITMAP IN gdiplus;
	INTEGER   hbm,;
	INTEGER   hpal,;
	INTEGER @ hbitmap
  
```  
***  


## Parameters:
hbm
[in] Handle to a GDI bitmap. 

hpal
[in] Handle to a GDI palette used to define the bitmap colors if hbm is not a device-independent bitmap (DIB). 

bitmap
[out] Handle to the GDI+ bitmap object.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
You are responsible for deleting the GDI bitmap and the GDI palette. However, you should not delete the GDI bitmap or the GDI palette until after the GDI+ Bitmap object is deleted or goes out of scope.  
  
Do not pass to the GDI+ Bitmap constructor a GDI bitmap or a GDI palette that is currently (or was previously) selected into a device context.  
  
***  

