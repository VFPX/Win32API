[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DrawDibDraw
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [msvfw32](../../Libraries.md#msvfw32)  
***  


#### The DrawDibDraw function draws a DIB to the screen.
***  


## Code examples:
[How to play AVI file on the _screen](../../samples/sample_430.md)  

## Declaration:
```foxpro  
BOOL DrawDibDraw(
  HDRAWDIB hdd,
  HDC hdc,
  int xDst,
  int yDst,
  int dxDst,
  int dyDst,
  LPBITMAPINFOHEADER lpbi,
  LPVOID lpBits,
  int xSrc,
  int ySrc,
  int dxSrc,
  int dySrc,
  UINT wFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawDibDraw IN msvfw32;
	INTEGER hdd,;
	INTEGER hdc,;
	INTEGER xDst,;
	INTEGER yDst,;
	INTEGER dxDst,;
	INTEGER dyDst,;
	INTEGER lpbi,;
	INTEGER lpBits,;
	INTEGER xSrc,;
	INTEGER ySrc,;
	INTEGER dxSrc,;
	INTEGER dySrc,;
	INTEGER wFlags
  
```  
***  


## Parameters:
hdd
Handle to a DrawDib DC.

hdc
Handle to the DC.

xDst
The x-coordinate, in MM_TEXT client coordinates, of the upper left corner of the destination rectangle.

yDst
The y-coordinate, in MM_TEXT client coordinates, of the upper left corner of the destination rectangle.

dxDst
Width, in MM_TEXT client coordinates, of the destination rectangle. If dxDst is - 1, the width of the bitmap is used. 

dyDst
Height, in MM_TEXT client coordinates, of the destination rectangle. If dyDst is - 1, the height of the bitmap is used.

lpbi
Pointer to the BITMAPINFOHEADER structure containing the image format.

lpBits
Pointer to the buffer that contains the bitmap bits.

xSrc
The x-coordinate, in pixels, of the upper left corner of the source rectangle. The coordinates (0,0) represent the upper left corner of the bitmap.

ySrc
The y-coordinate, in pixels, of the upper left corner of the source rectangle. The coordinates (0,0) represent the upper left corner of the bitmap.

dxSrc
Width, in pixels, of the source rectangle.

dySrc
Height, in pixels, of the source rectangle.

wFlags
Applicable flags for drawing.

  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  


## Comments:
The DrawDibDraw function is similar to the StretchDIBits function in that it provides image-stretching and dithering capabilities. However, the DrawDibDraw support image decompression, data-streaming, and a greater number of display adapters.   
  
Still, StretchDIBits is more diverse than the DrawDib functions and should be used when the DrawDib functions cannot provide the desired functionality.  
  
DrawDibDraw does not provide any means for doing transparency, colorkeying, raster ops or anything fancy like that, it is only capable of a simple "copy" of the source image to the target.  
  
***  

