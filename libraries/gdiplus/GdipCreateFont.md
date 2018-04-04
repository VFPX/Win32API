[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateFont
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a Font handle based on a FontFamily handle, a size, a font style, and a unit of measurement.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateFont(
	GDIPCONST GpFontFamily *fontFamily,
	REAL emSize,
	INT style,
	Unit unit, GpFont **font
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateFont IN gdiplus;
	INTEGER   fontFamily,;
	SINGLE    emSize,;
	INTEGER   fontstyle,;
	INTEGER   unit,;
	INTEGER @ fnt
  
```  
***  


## Parameters:
FontFamily
[in] FontFamily handle that specifies information such as the string that identifies the font family and the font family"s text metrics measured in design units. 

emSize
[in] Real number that specifies the em size of the font measured in the units specified in the unit parameter. 

fontstyle
[in] Optional. Integer that specifies the style of the typeface.

unit
[in] Optional. Element of the Unit enumeration that specifies the unit of measurement for the font size (UnitPoint=0). 

fnt
[out] Handle to the Font object.  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
When you no longer need the Font handle, call the GdipDeleteFont function.   
  
***  

