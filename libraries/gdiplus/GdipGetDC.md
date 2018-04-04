[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetDC
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets a handle to the device context associated with this Graphics object.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetDC(
	GpGraphics* graphics,
	HDC * hdc
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetDC IN gdiplus;
	INTEGER   graphics,;
	INTEGER @ hdc
  
```  
***  


## Parameters:
graphics
[in] Handle to a Graphics object obtained from GdipCreateFromHDC, GdipCreateFromHDC2, GdipCreateFromHWND or GdipGetImageGraphicsContext functions.

hdc
[out] Handle to the device context associated with this Graphics object.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
Each call to the GdipGetDC should be paired with a call to the GdipReleaseDC of that same Graphics handle.   
  
Do not make any API calls with this Graphics handle between the calls to GdipGetDC and GdipReleaseDC. If you attempt, the call will fail and will return ObjectBusy (4).   
  
***  

