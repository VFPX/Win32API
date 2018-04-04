[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetPropertyItemSize
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
img
[in] Handle to Image object

propId
[in] Integer that identifies the property item.

size
[out] Size of the property item in bytes.  
***  


## Return value:
Returns 0 on success.  
***  

