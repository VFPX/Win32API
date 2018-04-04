[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipRemovePropertyItem
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Removes a property item (piece of metadata) from this Image object.
***  


## Code examples:
[GDI+: reading and writing metadata in JPEG and TIFF files](../../samples/sample_461.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipRemovePropertyItem(
	GpImage *image,
	PROPID propId
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipRemovePropertyItem IN gdiplus;
	INTEGER img,;
	INTEGER propId
  
```  
***  


## Parameters:
img
[in] Handle to Image Object

propId
[in] Integer that identifies the property item to be removed.   
***  


## Return value:
If the method succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  


## Comments:
The GdipRemovePropertyItem removes a specified property from an Image object, but that property item is not removed from the file or stream that was used to construct the Image object.   
  
To save the image (with the property item removed) save it to a new JPEG file or stream, call GdipSaveImageToFile or GdipSaveImageToStream functions.  
  
***  

