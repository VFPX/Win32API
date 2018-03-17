<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDeletePen
Group: GDI+ Pen - Library: gdiplus    
***  


#### Deletes the specified Pen object.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDeletePen(
	GpPen *pen
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDeletePen IN gdiplus;
	INTEGER gdipen  
```  
***  


## Parameters:
```txt  
pen
[in] Handle to the Pen object created with GdipCreatePen1, GdipCreatePen2 or GdipClonePen functions.  
```  
***  


## Return value:
Returns 0 on success.  
***  

