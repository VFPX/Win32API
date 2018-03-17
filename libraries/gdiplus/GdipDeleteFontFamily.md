<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDeleteFontFamily
Group: GDI+ Font - Library: gdiplus    
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
```txt  
FontFamily
[in] Handle to the FontFamily object created with GdipCreateFontFamilyFromName, GdipCloneFontFamily or similar function.  
```  
***  


## Return value:
Returns 0 on success.  
***  

