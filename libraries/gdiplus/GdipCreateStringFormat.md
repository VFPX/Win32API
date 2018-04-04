[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateStringFormat
Group: [GDI+ StringFormat](../../functions_group.md#GDIplus_StringFormat)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Creates a StringFormat object based on string format flags and a language.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateStringFormat(
	INT formatAttributes,
	LANGID language,
	GpStringFormat **format
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateStringFormat IN gdiplus;
	INTEGER formatAttributes,;
	INTEGER language,;
	INTEGER @fmt  
```  
***  


## Parameters:
formatFlags
[in] Optional. Value that specifies the format flags that control most of the characteristics of the StringFormat object.

language
[in] Optional. Sixteen-bit value that specifies the language to use.

format
[out] Handle to the GDI+ StringFormat object  
***  


## Return value:
Returns 0 on success.  
***  

