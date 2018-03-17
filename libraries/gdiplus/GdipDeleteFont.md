<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDeleteFont
Group: GDI+ Font - Library: gdiplus    
***  


#### Deletes the specified Font object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDeleteFont(
	GpFont* font
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDeleteFont IN gdiplus;
	INTEGER fnt  
```  
***  


## Parameters:
```txt  
fnt
[in] Handle to the Font object created with GdipCreateFont, GdipCreateFontFromDC or similar function.  
```  
***  


## Return value:
Returns 0 on success.  
***  

