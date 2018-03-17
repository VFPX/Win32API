<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetPropertyItem
Group: GDI+ Image - Library: gdiplus    
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
```txt  
img
[in] Handle to Image object

propId
[in] Integer that identifies the property item to be retrieved.

propSize
[in] Integer that specifies the size, in bytes, of the property item to be retrieved. Call the GdipGetPropertyItemSize to

determine the size.

buffer
[out] Pointer to a PropertyItem object that receives the property item.  
```  
***  


## Return value:
Returns 0 on success.  
***  

