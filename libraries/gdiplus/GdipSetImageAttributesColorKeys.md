<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetImageAttributesColorKeys
Group: GDI+ ImageAttributes - Library: gdiplus    
***  


#### Sets the color key (transparency range) for a specified ColorAdjustType.
***  


## Code examples:
[GDI+: Color Transparency](../../samples/sample_549.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetImageAttributesColorKeys(
	GpImageAttributes *imageattr,
	ColorAdjustType type,
	BOOL enableFlag,
	ARGB colorLow,
	ARGB colorHigh)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetImageAttributesColorKeys IN gdiplus;
	INTEGER imageattr,;
	INTEGER ColorAdjustType,;
	INTEGER enableFlag,;
	LONG colorLow,;
	LONG colorHigh  
```  
***  


## Parameters:
```txt  
imageattr
[in] Handle to the ImageAttributes object.

type
[in] Element of the ColorAdjustType enumeration that specifies the category for which the color key is set.

enableFlag
[in] Enables a separate transparency range.

colorLow
[in] Lowest ARGB value in the transparency range.

colorHigh
[in] Highest ARGB value in the transparency range.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

