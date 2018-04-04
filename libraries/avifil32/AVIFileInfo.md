[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIFileInfo
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
***  


#### The AVIFileInfo function obtains information about an AVI file.
***  


## Code examples:
[Reading header information from AVI file](../../samples/sample_428.md)  
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[How to extract frames from AVI files](../../samples/sample_484.md)  

## Declaration:
```foxpro  
STDAPI AVIFileInfo(
  PAVIFILE pfile,
  AVIFILEINFO * pfi,
  LONG lSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIFileInfo IN avifil32;
	INTEGER   pfile,;
	STRING  @ pfi,;
	INTEGER   lSize
  
```  
***  


## Parameters:
pfile
Handle to an open AVI file.

pfi
Pointer to the structure used to return file information. Typically, this parameter points to an AVIFILEINFO structure.

lSize
Size, in bytes, of the structure.
  
***  


## Return value:
Returns zero if successful or an error otherwise.   
***  

