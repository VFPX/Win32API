<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateStringFormat
Group: GDI+ StringFormat - Library: gdiplus    
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
```txt  
formatFlags
[in] Optional. Value that specifies the format flags that control most of the characteristics of the StringFormat object.

language
[in] Optional. Sixteen-bit value that specifies the language to use.

format
[out] Handle to the GDI+ StringFormat object  
```  
***  


## Return value:
Returns 0 on success.  
***  

