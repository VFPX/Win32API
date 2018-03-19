[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Number of clipboard formats available

## Code:
```foxpro  
#DEFINE CF_TEXT              1
#DEFINE CF_BITMAP            2
#DEFINE CF_METAFILEPICT      3
#DEFINE CF_SYLK              4
#DEFINE CF_TIFF              6
#DEFINE CF_DIF               5
#DEFINE CF_OEMTEXT           7
#DEFINE CF_DIB               8
#DEFINE CF_PALETTE           9
#DEFINE CF_PENDATA          10
#DEFINE CF_RIFF             11
#DEFINE CF_WAVE             12
#DEFINE CF_UNICODETEXT      13
#DEFINE CF_ENHMETAFILE      14
#DEFINE CF_HDROP            15
#DEFINE CF_LOCALE           16
#DEFINE CF_DIBV5            17
DO declare

? "Number of formats currently on the clipboard: " +;
	LTRIM(STR(CountClipboardFormats()))

cBuffer = Chr(CF_TEXT) + Repli(Chr(0),3) +;
	Chr(CF_OEMTEXT) + Repli(Chr(0),3) +;
	Chr(CF_UNICODETEXT) + Repli(Chr(0),3)

? "First available text format, ID: " +;
	LTRIM(STR(GetPriorityClipboardFormat(@cBuffer, 3)))

PROCEDURE declare
	DECLARE INTEGER CountClipboardFormats IN user32

	DECLARE INTEGER GetPriorityClipboardFormat IN user32;
		STRING @paFormatPriorityList, INTEGER cFormats  
```  
***  


## Listed functions:
[CountClipboardFormats](../libraries/user32/CountClipboardFormats.md)  
[GetPriorityClipboardFormat](../libraries/user32/GetPriorityClipboardFormat.md)  
