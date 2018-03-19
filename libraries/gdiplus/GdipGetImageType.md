
## Function name : GdipGetImageType
Group: GDI+ Image - Library: gdiplus    
***  


#### Gets the type (bitmap or metafile) of this Image object.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImageType(
	GpImage *image,
	ImageType *type
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageType IN gdiplus;
	INTEGER   img,;
	INTEGER @ imgtype  
```  
***  


## Parameters:
img
[in] Handle to Image Object

imgtype
[out] ImageType enumeration value.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
<code>typedef enum {  
	ImageTypeUnknown = 0,  
	ImageTypeBitmap = 1,  
	ImageTypeMetafile = 2  
} ImageType;</code>  
  
***  

