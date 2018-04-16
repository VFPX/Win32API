[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageFlags
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets a set of flags that indicate certain attributes of this Image object.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetImageFlags(
	GpImage *image,
	UINT *flags
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageFlags IN gdiplus;
	INTEGER   img,;
	INTEGER @ imgflags  
```  
***  


## Parameters:
img
[in] Handle to Image Object

imgflags
[out] Set of single-bit flags. The flags are defined in the ImageFlags enumeration.

  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
```cpp
typedef enum {  
	ImageFlagsNone = 0,  
	ImageFlagsScalable = 0x0001,  
	ImageFlagsHasAlpha = 0x0002,  
	ImageFlagsHasTranslucent = 0x0004,  
	ImageFlagsPartiallyScalable = 0x0008,  
	ImageFlagsColorSpaceRGB = 0x0010,  
	ImageFlagsColorSpaceCMYK = 0x0020,  
	ImageFlagsColorSpaceGRAY = 0x0040,  
	ImageFlagsColorSpaceYCBCR = 0x0080,  
	ImageFlagsColorSpaceYCCK = 0x0100,  
	ImageFlagsHasRealDPI = 0x1000,  
	ImageFlagsHasRealPixelSize = 0x2000,  
	ImageFlagsReadOnly = 0x00010000,  
	ImageFlagsCaching = 0x00020000  
} ImageFlags;
```
  
***  

