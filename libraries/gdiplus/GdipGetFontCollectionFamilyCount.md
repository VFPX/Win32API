[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetFontCollectionFamilyCount
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets the number of font families contained in this font collection
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetFontCollectionFamilyCount(
	GpFontCollection* fontCollection,
	INT * numFound
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetFontCollectionFamilyCount IN gdiplus;
	INTEGER   fontCollection,;
	INTEGER @ numFound
  
```  
***  


## Parameters:
fontCollection
[in] Handle to a FontCollection object.

numFound
[out] Number of font families contained in this font collection  
***  


## Return value:
Returns 0 on success.  
***  

