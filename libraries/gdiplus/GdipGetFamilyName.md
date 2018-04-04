[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetFamilyName
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the name of this font family.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetFamilyName(
	GDIPCONST GpFontFamily *family,
	WCHAR name[LF_FACESIZE],
	LANGID language
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetFamilyName IN gdiplus;
	INTEGER  fontfamily,;
	STRING @ familyname,;
	INTEGER  language
  
```  
***  


## Parameters:
fontfamily
[in] Handle to Font Family Object.

familyname
[out] Name of this font family. 

language
[in] Optional. Sixteen-bit value that specifies the language to use.   
***  


## Return value:
If the method succeeds, it returns Ok, which is an element of the Status enumeration.  
***  

