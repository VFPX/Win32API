<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : AVIFileRelease
Group: Windows Multimedia - Library: avifil32    
***  


#### The AVIFileRelease function decrements the reference count of an AVI file interface handle and closes the file if the count reaches zero.
***  


## Code examples:
[Reading header information from AVI file](../../samples/sample_428.md)  
[Reading parameters of streams in AVI file](../../samples/sample_429.md)  
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  
[How to extract frames from AVI files](../../samples/sample_484.md)  

## Declaration:
```foxpro  
STDAPI_(ULONG) AVIFileRelease(
  PAVIFILE pfile
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIFileRelease IN avifil32;
	INTEGER pfile  
```  
***  


## Parameters:
```txt  
pfile
Handle to an open AVI file.
  
```  
***  


## Return value:
Returns the reference count of the file.  
***  

