[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ObtainUserAgentString
Group: [URL Monikers](../../functions_group.md#URL_Monikers)  -  Library: [urlmon](../../Libraries.md#urlmon)  
***  


#### Retrieves the user agent string in use.
***  


## Code examples:
[Obtaining current Internet Explorer browser version and UserAgent](../../samples/sample_142.md)  

## Declaration:
```foxpro  
HRESULT ObtainUserAgentString(
	DWORD dwOption,
	LPCSTR pcszUAOut,
	DWORD *cbSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ObtainUserAgentString IN urlmon;
	INTEGER   dwOption,;
	STRING  @ pcszUAOut,;
	INTEGER @ cbSize
  
```  
***  


## Parameters:
dwOption
Reserved. Must be set to 0.

pcszUAOut
Pointer to a string value that contains the user agent string currently being used. 

cbSize
Pointer to an unsigned long integer value that contains the length of the string.  
***  


## Return value:
Returns one of the following values: E_INVALIDARG, E_OUTOFMEMORY, NOERROR (0)  
***  

