[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageDecoders
Group: [GDI+](../../functions_group.md#GDIplus)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### The GetImageDecoders function gets an array of ImageCodecInfo objects that contain information about the available image decoders.
***  


## Code examples:
[GDI+: retrieving list of available image encoders and image decoders](../../samples/sample_459.md)  

## Declaration:
```foxpro  
Status GetImageDecoders(
	UINT numDecoders,
	UINT size,
	ImageCodecInfo *decoders
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageDecoders IN gdiplus As GetCoders;
	INTEGER   numDecoders,;
	INTEGER   sze,;
	STRING  @ decoders  
```  
***  


## Parameters:
numDecoders
[in] Integer that specifies the number of available image decoders. 

size
[in] Integer that specifies the size, in bytes, of the array of ImageCodecInfo objects.

decoders
[out] Pointer to a buffer that receives the array of ImageCodecInfo objects. You must allocate memory for this buffer.  
***  


## Return value:
If the function succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  


## Comments:
Prior to calling this function call GdipGetImageDecodersSize to determine numDecoders and size parameters.  
  
***  

