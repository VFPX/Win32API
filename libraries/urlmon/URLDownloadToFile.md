[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : URLDownloadToFile
Group: [URL Monikers](../../functions_group.md#URL_Monikers)  -  Library: [urlmon](../../Libraries.md#urlmon)  
***  


#### Downloads bits from the Internet and saves them to a file.
***  


## Code examples:
[How to download a file from HTTP server using URL Monikers functions](../../samples/sample_175.md)  
[The DetectAutoProxyUrl function identifies the auto-config script location](../../samples/sample_341.md)  

## Declaration:
```foxpro  
HRESULT URLDownloadToFile(
	LPUNKNOWN pCaller,
    LPCTSTR szURL,
    LPCTSTR szFileName,
    DWORD dwReserved,
    LPBINDSTATUSCALLBACK lpfnCB
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER URLDownloadToFile IN urlmon.dll;
	INTEGER pCaller,;
	STRING  szURL,;
	STRING  szFileName,;
	INTEGER dwReserved,;
	INTEGER lpfnCB  
```  
***  


## Parameters:
pCaller
Pointer to the controlling IUnknown interface of the calling Microsoft&reg; ActiveX&reg; component (if the caller is an ActiveX component). If the calling application is not an ActiveX component, this value can be set to NULL. 

szURL
Pointer to a string value containing the URL to be downloaded. Cannot be set to NULL. 

szFileName
Pointer to a string value containing the name of the file to create for bits that come from the download. 

dwReserved
Reserved. Must be set to 0.

lpfnCB
Pointer to the caller"s IBindStatusCallback interface.   
***  


## Return value:
Returns one of the following values: E_OUTOFMEMORY, S_OK  
***  

