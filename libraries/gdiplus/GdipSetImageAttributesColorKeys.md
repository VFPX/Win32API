[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSetImageAttributesColorKeys
Group: [GDI+ ImageAttributes](../../functions_group.md#GDIplus_ImageAttributes)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
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
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  

