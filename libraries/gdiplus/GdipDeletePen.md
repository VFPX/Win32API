[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipDeletePen
Group: [GDI+ Pen](../../functions_group.md#GDIplus_Pen)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
pen
[in] Handle to the Pen object created with GdipCreatePen1, GdipCreatePen2 or GdipClonePen functions.  
***  


## Return value:
Returns 0 on success.  
***  

