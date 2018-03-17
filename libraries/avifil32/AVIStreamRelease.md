<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : AVIStreamRelease
Group: Windows Multimedia - Library: avifil32    
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
```txt  
pavi
Handle to an open stream.
  
```  
***  


## Return value:
Returns the current reference count of the stream.  
***  

