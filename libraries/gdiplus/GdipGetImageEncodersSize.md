[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetImageEncodersSize
Group: [GDI+](../../functions_group.md#GDIplus)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### The GetImageEncodersSize function gets the number of available image encoders and the total size of the array of ImageCodecInfo objects that is returned by the GetImageEncoders function.
***  


## Code examples:
[GDI+: retrieving list of available image encoders and image decoders](../../samples/sample_459.md)  

## Declaration:
```foxpro  
Status GetImageEncodersSize(
	UINT *numEncoders,
	UINT *size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetImageEncodersSize IN gdiplus;
	INTEGER @ numEncoders,;
	INTEGER @ sze
  
```  
***  


## Parameters:
numEncoders
[out] Pointer to a UINT that receives the number of available image encoders. 

size
[out] Pointer to a UINT that receives the total size, in bytes, of the array of ImageCodecInfo objects that is returned by GetImageEncoders. 
  
***  


## Return value:
If the function succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  

