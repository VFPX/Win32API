<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetImageDecodersSize
Group: GDI+ - Library: gdiplus    
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
```txt  
numDecoders
[out] Pointer to a UINT that receives the number of available image decoders.

size
[out] Pointer to a UINT that receives the total size, in bytes, of the array of ImageCodecInfo objects that is returned by the GetImageDecoders function.  
```  
***  


## Return value:
If the function succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  

