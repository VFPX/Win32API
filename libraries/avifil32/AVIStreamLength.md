[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIStreamLength
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
***  


#### The AVIStreamLength function returns the length of the stream.
***  


## Code examples:
[Reading parameters of streams in AVI file](../../samples/sample_429.md)  

## Declaration:
```foxpro  
STDAPI_(LONG) AVIStreamLength(
  PAVISTREAM pavi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIStreamLength IN avifil32;
	INTEGER pavi  
```  
***  


## Parameters:
pavi
Handle to an open stream.
  
***  


## Return value:
Returns the stream"s length, in samples, if successful or -1 otherwise.  
***  

