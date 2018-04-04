[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIStreamRelease
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
***  


#### The AVIStreamRelease function decrements the reference count of an AVI stream interface handle, and closes the stream if the count reaches zero.
***  


## Code examples:
[Reading parameters of streams in AVI file](../../samples/sample_429.md)  
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[How to extract frames from AVI files](../../samples/sample_484.md)  

## Declaration:
```foxpro  
STDAPI_(LONG) AVIStreamRelease(
  PAVISTREAM pavi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIStreamRelease IN avifil32;
	INTEGER pavi  
```  
***  


## Parameters:
pavi
Handle to an open stream.
  
***  


## Return value:
Returns the current reference count of the stream.  
***  

