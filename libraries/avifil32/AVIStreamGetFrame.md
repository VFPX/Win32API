[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIStreamGetFrame
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
***  


#### The AVIStreamGetFrame function returns the address of a decompressed video frame.
***  


## Code examples:
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[How to extract frames from AVI files](../../samples/sample_484.md)  

## Declaration:
```foxpro  
STDAPI_(LPVOID) AVIStreamGetFrame(
  PGETFRAME pgf,
  LONG lPos
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIStreamGetFrame IN avifil32;
	INTEGER pgf,;
	INTEGER lPos  
```  
***  


## Parameters:
pgf
Pointer to a GetFrame object.

lPos
Position, in samples, within the stream of the desired frame.
  
***  


## Return value:
Returns a pointer to the frame data if successful or NULL otherwise.   
***  


## Comments:
The frame data is returned as a <Em>packed DIB</Em>. The returned frame is valid only until the next call to this function or the AVIStreamGetFrameClose function.  
  
The packed DIB contains BITMAPINFOHEADER structure, followed sometimes by palette table, and then followed by bitmap data -- all in continuous block of memory.  
  
***  

