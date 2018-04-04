[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipCreateImageAttributes
Group: [GDI+ ImageAttributes](../../functions_group.md#GDIplus_ImageAttributes)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
imageattr
[out] Handle to the ImageAttributes object.  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
An ImageAttributes object contains information about how bitmap and metafile colors are manipulated during rendering.   
  
When no longer needed the ImageAttributes object must be deleted by calling the GdipDisposeImageAttributes function.  
  
***  

