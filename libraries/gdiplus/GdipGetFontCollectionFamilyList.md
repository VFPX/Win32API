<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetFontCollectionFamilyList
Group: GDI+ Font - Library: gdiplus    
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
```txt  
fontCollection
[in] Handle to FontCollection object.

numSought
[in] Suggested number of font families in this font collection

gpfamilies
[out] Pointer to an array that receives the list of names.

numFound
[out] Pointer to an INT that receives the number of font families found in this collection. This number should be the same as the numSought value.
  
```  
***  


## Return value:
Returns 0 on success.  
***  


## Comments:
The interface of this function is some fuzzy. I do not think they really need <Em>numSought</Em> parameter to be supplied to the function. May be the idea is to give an option of retrieving only the top part of this list, which does not make sense either :)  
  
Though anyway, call GdipGetFontCollectionFamilyCount to get the number of Font Families found in this collection.  
  
***  

