<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipDisposeImageAttributes
Group: GDI+ ImageAttributes - Library: gdiplus    
***  


#### Disposes the ImageAttributes object created by GdipCreateImageAttributes function.
***  


## Code examples:
[GDI+: Color Transparency](../../samples/sample_549.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipDisposeImageAttributes(
	GpImageAttributes *imageattr)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipDisposeImageAttributes IN gdiplus;
	INTEGER imageattr  
```  
***  


## Parameters:
```txt  
imageattr
[in] Handle to the ImageAttributes object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

