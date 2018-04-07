[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateURLMonikerEx
Group: [URL Monikers](../../functions_group.md#URL_Monikers)  -  Library: [urlmon](../../Libraries.md#urlmon)  
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
pMkCtx
A pointer to an IMoniker interface of the URL moniker to use as the base context when the szURL parameter is a partial URL string. The pMkCtx parameter can be NULL.

szURL
A string value that contains the URL to be parsed.

ppmk
A pointer to an IMoniker interface for the new URL moniker.

dwFlags
A DWORD value that specifies which URL parser to use: URL_MK_LEGACY=0, URL_MK_UNIFORM=1  
***  


## Return value:
Returns S_OK (0) if successful, or an error value otherwise.  
***  


## Comments:
While URL Monitor can be created in VFP code, I am not sure yet if it has to be released and how without resorting to using external routines (IUnknown::Release).  
  
See also: [ShowHTMLDialog](../mshtml/ShowHTMLDialog.md).  
  
***  

