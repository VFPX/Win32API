
## Function name : GdipSetTextRenderingHint
Group: GDI+ Graphics - Library: gdiplus    
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

