[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDeleteStringFormat
Group: [GDI+ StringFormat](../../functions_group.md#GDIplus_StringFormat)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Deletes the specified StringFormat object .
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDeleteStringFormat(
	GpStringFormat *format
)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDeleteStringFormat IN gdiplus;
	INTEGER fmt  
```  
***  


## Parameters:
format
[in] Handle to the GDI+ StringFormat object created by GdipDeleteStringFormat function.  
***  


## Return value:
Returns 0 on success.  
***  

