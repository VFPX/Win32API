<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetDC
Group: GDI+ Graphics - Library: gdiplus    
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
```txt  
graphics
[in] Handle to a Graphics object obtained from GdipCreateFromHDC, GdipCreateFromHDC2, GdipCreateFromHWND or GdipGetImageGraphicsContext functions.

hdc
[out] Handle to the device context associated with this Graphics object.  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
Each call to the GdipGetDC should be paired with a call to the GdipReleaseDC of that same Graphics handle.   
  
Do not make any API calls with this Graphics handle between the calls to GdipGetDC and GdipReleaseDC. If you attempt, the call will fail and will return ObjectBusy (4).   
  
***  

