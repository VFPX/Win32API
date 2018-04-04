[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageDecodersSize
Group: [GDI+](../../functions_group.md#GDIplus)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### The GetImageDecodersSize function gets the number of available image decoders and the total size of the array of ImageCodecInfo objects that is returned by the GetImageDecoders function.
***  


## Code examples:
[GDI+: retrieving list of available image encoders and image decoders](../../samples/sample_459.md)  

## Declaration:
```foxpro  
Status GetImageDecodersSize(
	UINT *numDecoders,
	UINT *size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageDecodersSize IN gdiplus;
	INTEGER @ numDecoders,;
	INTEGER @ sze
  
```  
***  


## Parameters:
numDecoders
[out] Pointer to a UINT that receives the number of available image decoders.

size
[out] Pointer to a UINT that receives the total size, in bytes, of the array of ImageCodecInfo objects that is returned by the GetImageDecoders function.   
***  


## Return value:
If the function succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  

