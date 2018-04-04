[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDeleteFont
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
fnt
[in] Handle to the Font object created with GdipCreateFont, GdipCreateFontFromDC or similar function.  
***  


## Return value:
Returns 0 on success.  
***  

