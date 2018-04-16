[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipMeasureString
Group: [GDI+ Text](../../functions_group.md#GDIplus_Text)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Measures the extent of the string in the specified font, format, and layout rectangle.

***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipMeasureString(
	GpGraphics *graphics,
	GDIPCONST WCHAR *string,
	INT length,
	GDIPCONST GpFont *font,
	GDIPCONST RectF *layoutRect,
	GDIPCONST GpStringFormat *stringFormat,
	RectF *boundingBox,
	INT *codepointsFitted,
	INT *linesFilled
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipMeasureString IN gdiplus;
	INTEGER graphics,;
	STRING utxt,;
	INTEGER length,;
	INTEGER fnt,;
	STRING @layoutRect,;
	INTEGER stringFormat,;
	STRING @boundingBox,;
	INTEGER @codepointsFitted,;
	INTEGER @linesFilled  
```  
***  


## Parameters:
graphics
[in] Pointer to a Graphics object.

string
[in] Pointer to a wide-character string to be measured. 

length
[in] Integer that specifies the number of characters in the string array. The length parameter can be set to ?1 if the string is null terminated. 

font
[in] Pointer to a Font object that specifies the family name, size, and style of the font that is applied to the string. 

layoutRectSize
[in] Reference to a SizeF object that specifies the width and height of a rectangle that bounds the string. 

stringFormat
[in] Pointer to a StringFormat object that specifies the layout information, such as alignment, trimming, tab stops, and so forth. 

size
[out] Pointer to a SizeF object that receives the width and height of the rectangle that bounds the string. 

codepointsFitted
[out] Optional. Pointer to an INT that receives the number of characters that actually fit into the layout rectangle. The default value is a NULL pointer. 

linesFilled
[out] Optional. Pointer to an INT that receives the number of lines that actually fit into the layout rectangle. The default value is a NULL pointer. 
  
***  


## Return value:
If the method succeeds, it returns OK (0).  
***  


## Comments:
Read Doug Hennig"s article <a href="http://doughennig.blogspot.com/2006/04/forget-txtwidth-use-gdipmeasurestring.html">Forget TXTWIDTH - use GdipMeasureString</a>.  
  
See also: [GetTextExtentPoint32](../gdi32/GetTextExtentPoint32.md), [FONTMETRICS()](http://msdn2.microsoft.com/en-us/library/fhfdf28k(VS.80).aspx), [TXTWIDTH()](http://msdn2.microsoft.com/en-us/library/a93d7wy7(VS.80).aspx), [WFONT( )](http://msdn2.microsoft.com/en-us/library/bx88s7fs(VS.80).aspx)

***  

