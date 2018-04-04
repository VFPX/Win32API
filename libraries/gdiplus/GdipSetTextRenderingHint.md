[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetTextRenderingHint
Group: [GDI+ Graphics](../../functions_group.md#GDIplus_Graphics)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Sets the text rendering mode of this Graphics object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetTextRenderingHint(
	GpGraphics *graphics,
	TextRenderingHint mode
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetTextRenderingHint IN gdiplus;
	INTEGER graphics,;
	INTEGER TextRenderingHint  
```  
***  


## Parameters:
graphics
[in] Pointer to a Graphics object.

TextRenderingHint
[in] Element of the TextRenderingHint enumeration that specifies the process currently used by this Graphics object to render text.   
***  


## Return value:
If the call succeeds, it returns Ok, which is an element of the Status enumeration.  
***  

