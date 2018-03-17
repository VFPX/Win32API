<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDeleteStringFormat
Group: GDI+ StringFormat - Library: gdiplus    
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
```txt  
format
[in] Handle to the GDI+ StringFormat object created by GdipDeleteStringFormat function.  
```  
***  


## Return value:
Returns 0 on success.  
***  

