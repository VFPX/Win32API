[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIStreamReadFormat
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
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
pavi
Handle to an open stream.

lPos
Position in the stream used to obtain the format data.

lpFormat
Pointer to a buffer to contain the format data.

lpcbFormat
Pointer to a location indicating the size of the memory block referenced by lpFormat.
  
***  


## Return value:
Returns zero if successful or an error otherwise.   
***  


## Comments:
MSDN says that the argument <Em>pavi</Em> is a pointer to an IAVIStream interface. From the FoxPro point of view <Em>pavi</Em> is rather a pointer.  
  
***  

