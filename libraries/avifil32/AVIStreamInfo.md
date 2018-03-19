
## Function name : AVIStreamInfo
Group: Windows Multimedia - Library: avifil32    
***  


#### The AVIStreamInfo function obtains stream header information.
***  


## Code examples:
[Reading parameters of streams in AVI file](../../samples/sample_429.md)  

## Declaration:
```foxpro  
STDAPI AVIStreamInfo(
  PAVISTREAM pavi,
  AVISTREAMINFO * psi,
  LONG lSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIStreamInfo IN avifil32;
	INTEGER   pavi,;
	STRING  @ psi,;
	INTEGER   lSize
  
```  
***  


## Parameters:
pavi
Handle to an open stream.

psi
Pointer to a structure to contain the stream information.

lSize
Size, in bytes, of the structure used for psi.
  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  

