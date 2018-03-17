<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetFontCollectionFamilyCount
Group: GDI+ Font - Library: gdiplus    
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
```txt  
fontCollection
[in] Handle to a FontCollection object.

numFound
[out] Number of font families contained in this font collection  
```  
***  


## Return value:
Returns 0 on success.  
***  

