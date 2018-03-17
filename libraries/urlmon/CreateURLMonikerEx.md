<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CreateURLMonikerEx
Group: URL Monikers - Library: urlmon    
***  


#### Creates a URL moniker from a full URL, or from a base context URL moniker and a partial URL.
***  


## Code examples:
[Yet another modal dialog: now HTML-based](../../samples/sample_561.md)  

## Declaration:
```foxpro  
HRESULT CreateURLMonikerEx(
	IMoniker *pMkCtx,
	LPCWSTR szURL,
	IMoniker **ppmk,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateURLMonikerEx IN urlmon;
	INTEGER pMkCtx,;
	STRING szURL,;
	INTEGER @ppmk,;
	LONG dwFlags  
```  
***  


## Parameters:
```txt  
pMkCtx
A pointer to an IMoniker interface of the URL moniker to use as the base context when the szURL parameter is a partial URL string. The pMkCtx parameter can be NULL.

szURL
A string value that contains the URL to be parsed.

ppmk
A pointer to an IMoniker interface for the new URL moniker.

dwFlags
A DWORD value that specifies which URL parser to use: URL_MK_LEGACY=0, URL_MK_UNIFORM=1  
```  
***  


## Return value:
Returns S_OK (0) if successful, or an error value otherwise.  
***  


## Comments:
While URL Monitor can be created in VFP code, I am not sure yet if it has to be released and how without resorting to using external routines (IUnknown::Release).  
  
See also: ShowHTMLDialog   
  
***  

