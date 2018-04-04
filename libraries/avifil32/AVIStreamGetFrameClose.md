[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIStreamGetFrameClose
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
***  


#### The AVIStreamGetFrameClose function releases resources used to decompress video frames.
***  


## Code examples:
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[How to extract frames from AVI files](../../samples/sample_484.md)  

## Declaration:
```foxpro  
STDAPI AVIStreamGetFrameClose(
  PGETFRAME pget
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIStreamGetFrameClose IN avifil32;
	INTEGER pget  
```  
***  


## Parameters:
pget
Handle returned from the AVIStreamGetFrameOpen function.
  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  

