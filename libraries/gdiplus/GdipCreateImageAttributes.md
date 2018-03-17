<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipCreateImageAttributes
Group: GDI+ ImageAttributes - Library: gdiplus    
***  


#### Creates new ImageAttributes object.
***  


## Code examples:
[GDI+: Color Transparency](../../samples/sample_549.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipCreateImageAttributes(
	GpImageAttributes **imageattr)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipCreateImageAttributes IN gdiplus;
	INTEGER @imageattr  
```  
***  


## Parameters:
```txt  
imageattr
[out] Handle to the ImageAttributes object.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
An ImageAttributes object contains information about how bitmap and metafile colors are manipulated during rendering.   
  
When no longer needed the ImageAttributes object must be deleted by calling the GdipDisposeImageAttributes function.  
  
***  

