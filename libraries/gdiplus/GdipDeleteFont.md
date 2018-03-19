
## Function name : GdipDeleteFont
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
fnt
[in] Handle to the Font object created with GdipCreateFont, GdipCreateFontFromDC or similar function.  
***  


## Return value:
Returns 0 on success.  
***  

