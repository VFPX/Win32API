<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateFontFamilyFromName
Group: GDI+ Font - Library: gdiplus    
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
```txt  
familyname
[in] Name of the font family.

fontCollection
[in] Optional. FontCollection handle that specifies the collection that the font family belongs to.

FontFamily
[out] Handle to the FontFamily object.
  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
When you no longer need the FontFamily handle, call the GdipDeleteFontFamily function.  
  
***  

