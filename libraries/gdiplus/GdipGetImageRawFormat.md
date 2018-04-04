[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageRawFormat
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets a globally unique identifier (GUID) that identifies the format of this Image object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImageRawFormat(
	GpImage *image,
	GUID *format
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageRawFormat IN gdiplus;
	INTEGER   img,;
	STRING  @ guid  
```  
***  


## Parameters:
img
[in] Handle to Image Object

guid
[out] Pointer to a GUID that receives the format identifier.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
GUIDs that identify various file formats are defined in Gdiplusimaging.h.  
  
The StringFromGUID2 converts a globally unique identifier (GUID) into a string of printable characters.  
  
***  

