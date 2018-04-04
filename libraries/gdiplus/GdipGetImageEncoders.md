[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageEncoders
Group: [GDI+](../../functions_group.md#GDIplus)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### The GetImageEncoders function gets an array of ImageCodecInfo objects that contain information about the available image encoders.
***  


## Code examples:
[GDI+: retrieving list of available image encoders and image decoders](../../samples/sample_459.md)  

## Declaration:
```foxpro  
Status GetImageEncoders(
	UINT numEncoders,
	UINT size,
	ImageCodecInfo *encoders
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageEncoders IN gdiplus;
	INTEGER   numEncoders,;
	INTEGER   sze,;
	STRING  @ encoders
  
```  
***  


## Parameters:
numEncoders
[in] Integer that specifies the number of available image encoders. 

size
[in] Integer that specifies the size, in bytes, of the array of ImageCodecInfo objects.

encoders
[out] Pointer to a buffer that receives the array of ImageCodecInfo objects.  
***  


## Return value:
If the function succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  


## Comments:
Prior to calling this function call GdipGetImageEncodersSize to determine <Em>numEncoders</Em> and <Em>size</Em> parameters.  
  
***  

