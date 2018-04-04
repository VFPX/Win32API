[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDIBits
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetDIBits function retrieves the bits of the specified compatible bitmap and copies them into a buffer as a DIB using the specified format. 
***  


## Code examples:
[How to print FoxPro form](../../samples/sample_158.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[Converting image file to .ICO file](../../samples/sample_503.md)  

## Declaration:
```foxpro  
int GetDIBits(
  HDC hdc,           // handle to DC
  HBITMAP hbmp,      // handle to bitmap
  UINT uStartScan,   // first scan line to set
  UINT cScanLines,   // number of scan lines to copy
  LPVOID lpvBits,    // array for bitmap bits
  LPBITMAPINFO lpbi, // bitmap data buffer
  UINT uUsage        // RGB or palette index
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDIBits IN gdi32;
	INTEGER   hdc,;
	INTEGER   hbmp,;
	INTEGER   uStartScan,;
	INTEGER   cScanLines,;
	INTEGER   lpvBits,;
	STRING  @ lpbi,;
	INTEGER   uUsage  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

hbmp 
[in] Handle to the bitmap. This must be a compatible bitmap (DDB). 

uStartScan 
[in] Specifies the first scan line to retrieve. 

cScanLines 
[in] Specifies the number of scan lines to retrieve. 

lpvBits 
[out] Pointer to a buffer to receive the bitmap data. 

lpbi 
[in/out] Pointer to a BITMAPINFO structure that specifies the desired format for the DIB data. 

uUsage 
[in] Specifies the format of the bmiColors member of the BITMAPINFO structure.   
***  


## Return value:
If the lpvBits parameter is non-NULL and the function succeeds, the return value is the number of scan lines copied from the bitmap.  
***  


## Comments:
DDB = Device-Dependent Bitmap.  
  
DIB = Device-Independent Bitmap: is not a GDI graphic object; cannot be selected into a device context; can be rendered to a device context directly.  
  
***  

