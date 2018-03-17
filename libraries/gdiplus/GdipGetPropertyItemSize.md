<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetPropertyItemSize
Group: GDI+ Image - Library: gdiplus    
***  


#### Gets the size, in bytes, of a specified property item of this Image object.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetPropertyItemSize(
	GpImage *image,
	PROPID propId,
	UINT* size
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetPropertyItemSize IN gdiplus;
	INTEGER   img,;
	INTEGER   propId,;
	INTEGER @ sze
  
```  
***  


## Parameters:
```txt  
img
[in] Handle to Image object

propId
[in] Integer that identifies the property item.

size
[out] Size of the property item in bytes.  
```  
***  


## Return value:
Returns 0 on success.  
***  

