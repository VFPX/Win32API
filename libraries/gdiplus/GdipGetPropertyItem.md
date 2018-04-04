[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetPropertyItem
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets a specified property item (piece of metadata) from this Image object.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetPropertyItem(
	GpImage *image,
	PROPID propId,
	UINT propSize,
	PropertyItem* buffer
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetPropertyItem IN gdiplus;
	INTEGER   img,;
	INTEGER   propId,;
	INTEGER   propSize,;
	STRING  @ buffer  
```  
***  


## Parameters:
img
[in] Handle to Image object

propId
[in] Integer that identifies the property item to be retrieved. 

propSize
[in] Integer that specifies the size, in bytes, of the property item to be retrieved. Call the GdipGetPropertyItemSize to 

determine the size. 

buffer
[out] Pointer to a PropertyItem object that receives the property item.  
***  


## Return value:
Returns 0 on success.  
***  

