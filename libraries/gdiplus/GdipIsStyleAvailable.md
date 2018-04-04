[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipIsStyleAvailable
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Determines whether the specified style is available for this font family.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipIsStyleAvailable(
	GDIPCONST GpFontFamily *family,
	INT style,
	BOOL * IsStyleAvailable
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipIsStyleAvailable IN gdiplus;
	INTEGER   fontfamily,;
	INTEGER   fontstyle,;
	INTEGER @ IsStyleAvailable
  
```  
***  


## Parameters:
fontfamily
[in] Handle to Font Family Object.

fontstyle
[in] Integer that specifies the style of the typeface.

IsStyleAvailable
[out] Set to True if requested style is available.  
***  


## Return value:
Returns 0 if the call to the GdipIsStyleAvailable is successful.  
***  

