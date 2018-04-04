[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StretchBlt
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Copies a bitmap from a source rectangle into a destination rectangle, stretching or compressing the bitmap to fit the dimensions of the destination rectangle, if necessary.
***  


## Code examples:
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[Form Magnifier](../../samples/sample_414.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
BOOL StretchBlt(
  HDC hdcDest,      // handle to destination DC
  int nXOriginDest, // x-coord of destination upper-left corner
  int nYOriginDest, // y-coord of destination upper-left corner
  int nWidthDest,   // width of destination rectangle
  int nHeightDest,  // height of destination rectangle
  HDC hdcSrc,       // handle to source DC
  int nXOriginSrc,  // x-coord of source upper-left corner
  int nYOriginSrc,  // y-coord of source upper-left corner
  int nWidthSrc,    // width of source rectangle
  int nHeightSrc,   // height of source rectangle
  DWORD dwRop       // raster operation code
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StretchBlt IN gdi32;
	INTEGER hdcDest,;
	INTEGER nXOriginDest,;
	INTEGER nYOriginDest,;
	INTEGER nWidthDest,;
	INTEGER nHeightDest,;
	INTEGER hdcSrc,;
	INTEGER nXOriginSrc,;
	INTEGER nYOriginSrc,;
	INTEGER nWidthSrc,;
	INTEGER nHeightSrc,;
	INTEGER dwRop  
```  
***  


## Parameters:
hdcDest 
[in] Handle to the destination device context. 

nXOriginDest 
[in] Specifies the x-coordinate, in logical units, of the upper-left corner of the destination rectangle. 

nYOriginDest 
[in] Specifies the y-coordinate, in logical units, of the upper-left corner of the destination rectangle. 

nWidthDest 
[in] Specifies the width, in logical units, of the destination rectangle. 

nHeightDest 
[in] Specifies the height, in logical units, of the destination rectangle. 

hdcSrc 
[in] Handle to the source device context. 

nXOriginSrc 
[in] Specifies the x-coordinate, in logical units, of the upper-left corner of the source rectangle. 

nYOriginSrc 
[in] Specifies the y-coordinate, in logical units, of the upper-left corner of the source rectangle. 

nWidthSrc 
[in] Specifies the width, in logical units, of the source rectangle. 

nHeightSrc 
[in] Specifies the height, in logical units, of the source rectangle. 

dwRop 
[in] Specifies the raster operation to be performed.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Not all devices support the StretchBlt function. For more information, see the GetDeviceCaps.  
  
***  

