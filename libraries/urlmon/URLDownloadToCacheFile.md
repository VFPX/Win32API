[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : URLDownloadToCacheFile
Group: [URL Monikers](../../functions_group.md#URL_Monikers)  -  Library: [urlmon](../../Libraries.md#urlmon)  
***  


#### Downloads data into the Internet cache and returns the file name of the cache location for retrieving the bits.
***  


## Code examples:
[Accessing examples contained in this reference from a VFP application](../../samples/sample_197.md)  
[GDI+: converting text strings to images and saving in a graphics file](../../samples/sample_513.md)  

## Declaration:
```foxpro  
HRESULT URLDownloadToCacheFile(
	LPUNKNOWN lpUnkcaller,
	LPCSTR szURL,
	LPTSTR szFileName,
	DWORD dwBufLength,
	DWORD dwReserved,
	IBindStatusCallback *pBSC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER URLDownloadToCacheFile IN urlmon;
	INTEGER   lpUnkcaller,;
	STRING    szURL,;
	STRING  @ szFileName,;
	INTEGER   dwBufLength,;
	INTEGER   dwReserved,;
	INTEGER   pBSC  
```  
***  


## Parameters:
lpUnkcaller
Pointer to the controlling IUnknown interface of the calling Microsoft&reg; ActiveX&reg; component (if the caller is an ActiveX component).

szURL
Pointer to a string value that contains the URL to be downloaded. This cannot be set to NULL. 

szFileName
Pointer to a string value that contains the name of the downloaded file. This cannot be set to NULL. 

dwBufLength
Unsigned long integer value that contains the size of the szFileName buffer in bytes. 

dwReserved
Reserved. Must be set to 0.

pBSC
Pointer to the caller"s IBindStatusCallback interface.  
***  


## Return value:
Returns one of the following values: E_FAIL, E_OUTOFMEMORY, S_OK (0).  
***  


## Comments:
This function always returns a file name if the download operation succeeds.  
  
***  

