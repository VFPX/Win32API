<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipIsStyleAvailable
Group: GDI+ Font - Library: gdiplus    
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
```txt  
fontfamily
[in] Handle to Font Family Object.

fontstyle
[in] Integer that specifies the style of the typeface.

IsStyleAvailable
[out] Set to True if requested style is available.  
```  
***  


## Return value:
Returns 0 if the call to the GdipIsStyleAvailable is successful.  
***  

