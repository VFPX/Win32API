[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDeleteFontFamily
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Deletes the specified FontFamily object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDeleteFontFamily(
	GpFontFamily *FontFamily
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDeleteFontFamily IN gdiplus;
	INTEGER FontFamily  
```  
***  


## Parameters:
FontFamily  
[in] Handle to the FontFamily object created with GdipCreateFontFamilyFromName, GdipCloneFontFamily or similar function.  
***  


## Return value:
Returns 0 on success.  
***  

