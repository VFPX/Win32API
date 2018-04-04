[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipNewInstalledFontCollection
Group: [GDI+ Font](../../functions_group.md#GDIplus_Font)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Represents the fonts installed on the system
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipNewInstalledFontCollection(
	GpFontCollection** fontCollection
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipNewInstalledFontCollection IN gdiplus;
	INTEGER @ fontCollection  
```  
***  


## Parameters:
fontCollection
[out] Handle to the FontCollection object.  
***  


## Return value:
Returns 0 on success.  
***  

