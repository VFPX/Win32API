<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : AVIStreamReadFormat
Group: Windows Multimedia - Library: avifil32    
***  


#### The AVIStreamReadFormat function reads the stream format data.
***  


## Code examples:
[How to play AVI file on the _screen](../../samples/sample_430.md)  

## Declaration:
```foxpro  
STDAPI AVIStreamReadFormat(
  PAVISTREAM pavi,
  LONG lPos,
  LPVOID lpFormat,
  LONG * lpcbFormat
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIStreamReadFormat IN avifil32;
	INTEGER   pavi,;
	INTEGER   lPos,;
	STRING  @ lpFormat,;
	INTEGER @ lpcbFormat
  
```  
***  


## Parameters:
```txt  
pavi
Handle to an open stream.

lPos
Position in the stream used to obtain the format data.

lpFormat
Pointer to a buffer to contain the format data.

lpcbFormat
Pointer to a location indicating the size of the memory block referenced by lpFormat.
  
```  
***  


## Return value:
Returns zero if successful or an error otherwise.   
***  


## Comments:
MSDN says that the argument <Em>pavi</Em> is a pointer to an IAVIStream interface. From the FoxPro point of view <Em>pavi</Em> is rather a pointer.  
  
***  

