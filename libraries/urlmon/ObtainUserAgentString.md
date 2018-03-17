<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ObtainUserAgentString
Group: URL Monikers - Library: urlmon    
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
```txt  
dwOption
Reserved. Must be set to 0.

pcszUAOut
Pointer to a string value that contains the user agent string currently being used.

cbSize
Pointer to an unsigned long integer value that contains the length of the string.  
```  
***  


## Return value:
Returns one of the following values: E_INVALIDARG, E_OUTOFMEMORY, NOERROR (0)  
***  

