[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StretchDIBits
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The StretchDIBits function copies the color data for a rectangle of pixels in a DIB to the specified destination rectangle.
***  


## Code examples:
[How to print FoxPro form](../../samples/sample_158.md)  
[How to print a bitmap file](../../samples/sample_211.md)  

## Declaration:
```foxpro  
int StretchDIBits(
  HDC hdc,                      // handle to DC
  int XDest,                    // x-coord of dest. upper-left
  int YDest,                    // y-coord of dest. upper-left
  int nDestWidth,               // width of dest. rectangle
  int nDestHeight,              // height of dest. rectangle
  int XSrc,                     // x-coord of src upper-left
  int YSrc,                     // y-coord of src upper-left
  int nSrcWidth,                // width of src rectangle
  int nSrcHeight,               // height of src rectangle
  CONST VOID *lpBits,           // bitmap bits
  CONST BITMAPINFO *lpBitsInfo, // bitmap data
  UINT iUsage,                  // usage options
  DWORD dwRop                   // raster operation code
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StretchDIBits IN gdi32;
	INTEGER   hdc,;
	INTEGER   XDest,;
	INTEGER   YDest,;
	INTEGER   nDestWidth,;
	INTEGER   nDestHeight,;
	INTEGER   XSrc,;
	INTEGER   YSrc,;
	INTEGER   nSrcWidth,;
	INTEGER   nSrcHeight,;
	INTEGER   lpBits,;
	STRING  @ lpBitsInfo,;
	INTEGER   iUsage,;
	INTEGER   dwRop
  
```  
***  


## Parameters:
hdc 
[in] Handle to the destination device context. 

XDest 
[in] Specifies the x-coordinate, in logical units, of the upper-left corner of the destination rectangle. 

YDest 
[in] Specifies the y-coordinate, in logical units, of the upper-left corner of the destination rectangle. 

nDestWidth 
[in] Specifies the width, in logical units, of the destination rectangle. 

nDestHeight 
[in] Specifies the height, in logical units, of the destination rectangle. 

XSrc 
[in] Specifies the x-coordinate, in pixels, of the source rectangle in the DIB. 

YSrc 
[in] Specifies the y-coordinate, in pixels, of the source rectangle in the DIB. 

nSrcWidth 
[in] Specifies the width, in pixels, of the source rectangle in the DIB. 

nSrcHeight 
[in] Specifies the height, in pixels, of the source rectangle in the DIB. 

lpBits 
[in] Pointer to the DIB bits, which are stored as an array of bytes.

lpBitsInfo 
[in] Pointer to a BITMAPINFO structure that contains information about the DIB. 

iUsage 
[in] Specifies whether the bmiColors member of the BITMAPINFO structure was provided and, if so, whether bmiColors contains explicit red, green, blue (RGB) values or indexes. 

dwRop 
[in] Specifies how the source pixels, the destination device context"s current brush, and the destination pixels are to be combined to form the new image.   
***  


## Return value:
If the function succeeds, the return value is the number of scan lines copied. If the function fails, the return value is GDI_ERROR (0xFFFF).  
***  

