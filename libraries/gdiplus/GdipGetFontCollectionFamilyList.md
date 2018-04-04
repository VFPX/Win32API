[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetFontCollectionFamilyList
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets list of the font families contained in this font collection.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetFontCollectionFamilyList(
	GpFontCollection* fontCollection,
	INT numSought,
	GpFontFamily* gpfamilies[],
	INT* numFound
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetFontCollectionFamilyList IN gdiplus;
	INTEGER   fontCollection,;
	INTEGER   numSought,;
	STRING  @ gpfamilies,;
	INTEGER @ numFound
  
```  
***  


## Parameters:
fontCollection
[in] Handle to FontCollection object.

numSought
[in] Suggested number of font families in this font collection

gpfamilies
[out] Pointer to an array that receives the list of names.

numFound
[out] Pointer to an INT that receives the number of font families found in this collection. This number should be the same as the numSought value.
  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
The interface of this function is some fuzzy. I do not think they really need <Em>numSought</Em> parameter to be supplied to the function. May be the idea is to give an option of retrieving only the top part of this list, which does not make sense either :)  
  
Though anyway, call GdipGetFontCollectionFamilyCount to get the number of Font Families found in this collection.  
  
***  

