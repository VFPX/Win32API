[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTextExtentPoint32
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetTextExtentPoint32 function computes the width and height of the specified string of text.
***  


## Code examples:
[Vertical Label control](../../samples/sample_398.md)  

## Declaration:
```foxpro  
BOOL GetTextExtentPoint32(
  HDC hdc,           // handle to DC
  LPCTSTR lpString,  // text string
  int cbString,      // characters in string
  LPSIZE lpSize      // string size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTextExtentPoint32 IN gdi32;
	INTEGER   hdc,;
	STRING    lpString,;
	INTEGER   cbString,;
	STRING  @ lpSize
  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

lpString 
[in] Pointer to a buffer that specifies the text string.

cbString 
[in] Specifies the length of the lpString buffer. For the ANSI function it is a BYTE count and for the Unicode function it is a WORD count.

lpSize 
[out] Pointer to a SIZE structure that receives the dimensions of the string, in logical units.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The string does not need to be zero-terminated, because the cbString parameter specifies the length of the string.  
  
See also: [GdipMeasureString](../gdiplus/GdipMeasureString.md), [TXTWIDTH()](http://msdn2.microsoft.com/en-us/library/a93d7wy7(VS.80).aspx), 
[WFONT( )](http://msdn2.microsoft.com/en-us/library/bx88s7fs(VS.80).aspx)  


***  

