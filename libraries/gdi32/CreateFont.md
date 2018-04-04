[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateFont
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Creates a logical font with the specified characteristics. The logical font can subsequently be selected as the font for any device.
***  


## Code examples:
[Printing text on the main VFP window](../../samples/sample_035.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  

## Declaration:
```foxpro  
HFONT CreateFont(
  int nHeight,               // height of font
  int nWidth,                // average character width
  int nEscapement,           // angle of escapement
  int nOrientation,          // base-line orientation angle
  int fnWeight,              // font weight
  DWORD fdwItalic,           // italic attribute option
  DWORD fdwUnderline,        // underline attribute option
  DWORD fdwStrikeOut,        // strikeout attribute option
  DWORD fdwCharSet,          // character set identifier
  DWORD fdwOutputPrecision,  // output precision
  DWORD fdwClipPrecision,    // clipping precision
  DWORD fdwQuality,          // output quality
  DWORD fdwPitchAndFamily,   // pitch and family
  LPCTSTR lpszFace           // typeface name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateFont IN gdi32;
	INTEGER nHeight,;
	INTEGER nWidth,;
	INTEGER nEscapement,;
	INTEGER nOrientation,;
	INTEGER fnWeight,;
	INTEGER fdwItalic,;
	INTEGER fdwUnderline,;
	INTEGER fdwStrikeOut,;
	INTEGER fdwCharSet,;
	INTEGER fdwOutputPrecision,;
	INTEGER fdwClipPrecision,;
	INTEGER fdwQuality,;
	INTEGER fdwPitchAndFamily,;
	STRING  lpszFace
  
```  
***  


## Parameters:
nHeight 
[in] Specifies the height, in logical units, of the font"s character cell or character.

nWidth 
[in] Specifies the average width, in logical units, of characters in the requested font.

nEscapement 
[in] Specifies the angle, in tenths of degrees, between the escapement vector and the x-axis of the device.

nOrientation 
[in] Specifies the angle, in tenths of degrees, between each character"s base line and the x-axis of the device. 

fnWeight 
[in] Specifies the weight of the font in the range 0 through 1000. 

fdwItalic 
[in] Specifies an italic font if set to TRUE. 

fdwUnderline 
[in] Specifies an underlined font if set to TRUE. 

fdwStrikeOut 
[in] Specifies a strikeout font if set to TRUE. 

fdwCharSet 
[in] Specifies the character set. 

fdwOutputPrecision 
[in] Specifies the output precision.

fdwClipPrecision 
[in] Specifies the clipping precision. 

fdwQuality 
[in] Specifies the output quality. 

fdwPitchAndFamily 
[in] Specifies the pitch and family of the font. 

lpszFace 
[in] Pointer to a null-terminated string that specifies the typeface name of the font. 
  
***  


## Return value:
If the function succeeds, the return value is a handle to a logical font. If the function fails, the return value is NULL. 
  
***  


## Comments:
Created handle to the font can be passed to a device context using the SelectObject function. To delete a font use DeleteObject function, before your program ends.  
  
***  

