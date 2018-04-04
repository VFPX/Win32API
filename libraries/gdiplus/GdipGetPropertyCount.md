[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetPropertyCount
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the number of properties (pieces of metadata) stored in this Image object. 
***  


## Code examples:
[GDI+: reading and writing metadata in JPEG and TIFF files](../../samples/sample_461.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetPropertyCount(
	GpImage *image,
	UINT* numOfProperty
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetPropertyCount IN gdiplus;
	INTEGER   img,;
	INTEGER @ numOfProperty
  
```  
***  


## Parameters:
img
[in] Handle to Image object

numofproperty
[out] Number of properties stored in this Image object  
***  


## Return value:
Returns 0 on success.  
***  

