[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateFontFamilyFromName
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a FontFamily handle based on specified font family name.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateFontFamilyFromName(
	GDIPCONST WCHAR *name,
	GpFontCollection *fontCollection,
	GpFontFamily **FontFamily
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateFontFamilyFromName IN gdiplus;
	STRING    familyname,;
	INTEGER   fontCollection,;
	INTEGER @ FontFamily
  
```  
***  


## Parameters:
familyname
[in] Name of the font family. 

fontCollection
[in] Optional. FontCollection handle that specifies the collection that the font family belongs to. 

FontFamily
[out] Handle to the FontFamily object.
  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
When you no longer need the FontFamily handle, call the GdipDeleteFontFamily function.  
  
***  

