[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AVIFileOpen
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [avifil32](../../Libraries.md#avifil32)  
***  


#### The AVIFileOpen function opens an AVI file and returns the address of a file interface used to access it.
***  


## Code examples:
[Reading header information from AVI file](../../samples/sample_428.md)  
[Reading parameters of streams in AVI file](../../samples/sample_429.md)  
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  
[How to extract frames from AVI files](../../samples/sample_484.md)  

## Declaration:
```foxpro  
STDAPI AVIFileOpen(
  PAVIFILE * ppfile,
  LPCTSTR szFile,
  UINT mode,
  CLSID  pclsidHandler
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AVIFileOpen IN avifil32;
	INTEGER @ ppfile,;
	STRING    szFile,;
	INTEGER   mode,;
	INTEGER   pclsidHandler
  
```  
***  


## Parameters:
ppfile
Pointer to a buffer that receives the new IAVIFile interface pointer.

szFile
Null-terminated string containing the name of the file to open.

mode
Access mode to use when opening the file.

pclsidHandler
Pointer to a class identifier of the standard or custom handler you want to use.
  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  

