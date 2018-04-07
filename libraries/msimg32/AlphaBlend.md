[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AlphaBlend
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [msimg32](../../Libraries.md#msimg32)  
***  


#### The AlphaBlend function displays bitmaps that have transparent or semitransparent pixels.
***  


## Code examples:
[Displaying bitmap using the AlphaBlend function](../../samples/sample_293.md)  

## Declaration:
```foxpro  
BOOL AlphaBlend(
  HDC hdcDest,             // handle to dest DC
  int nXOriginDest,        // x-coord upper-left
  int nYOriginDest,        // y-coord upper-left
  int nWidthDest,          // destination width
  int nHeightDest,         // destination height
  HDC hdcSrc,              // handle to source DC
  int nXOriginSrc,         // x-coord upper-left
  int nYOriginSrc,         // y-coord upper-left
  int nWidthSrc,           // source width
  int nHeightSrc,          // source height
  BLENDFUNCTION blendFunc  // alpha-blending func
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AlphaBlend IN Msimg32;
	INTEGER hDestDC,;
	INTEGER x,;
	INTEGER y,;
	INTEGER nWidth,;
	INTEGER nHeight,;
	INTEGER hSrcDC,;
	INTEGER xSrc,;
	INTEGER ySrc,;
	INTEGER nWidthSrc,;
	INTEGER nHeightSrc,;
	INTEGER blendFunction
  
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

blendFunction 
[in] Specifies the alpha-blending function for source and destination bitmaps.  
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
See also: [GdipDrawImageRectRectI](../gdiplus/GdipDrawImageRectRectI.md).  
  
***  

