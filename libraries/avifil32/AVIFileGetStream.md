[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIFileGetStream
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
***  


#### The AVIFileGetStream function returns the address of a stream interface that is associated with a specified AVI file.
***  


## Code examples:
[Reading parameters of streams in AVI file](../../samples/sample_429.md)  
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[How to extract frames from AVI files](../../samples/sample_484.md)  

## Declaration:
```foxpro  
STDAPI AVIFileGetStream(
  PAVIFILE pfile,
  PAVISTREAM * ppavi,
  DWORD fccType,
  LONG lParam
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIFileGetStream IN avifil32;
	INTEGER   pfile,;
	INTEGER @ ppavi,;
	INTEGER   fccType,;
	INTEGER   lParam
  
```  
***  


## Parameters:
pfile
Handle to an open AVI file.

ppavi
Pointer to the new stream interface.

fccType
Four-character code indicating the type of stream to open.

lParam
Count of the stream type. Identifies which occurrence of the specified stream type to access. 
  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  

