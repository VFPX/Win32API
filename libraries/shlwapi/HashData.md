<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : HashData
Group: Shell Lightweight Utility APIs -- misc. functions - Library: shlwapi    
***  


#### Hashes an array of data.
***  


## Code examples:
[Creating hash values for the list of names](../../samples/sample_179.md)  

## Declaration:
```foxpro  
HRESULT HashData(
	LPBYTE pbData,
	DWORD cbData,
	LPBYTE pbHash,
	DWORD cbHash
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HashData IN shlwapi;
	STRING  @ pbData,;
	INTEGER   cbData,;
	STRING  @ pbHash,;
	INTEGER   cbHash  
```  
***  


## Parameters:
```txt  
pbData
[in] Pointer to the data array.

cbData
[in] Number of elements in pbData.

pbHash
[out] Value used to return the hashed array.

cbHash
[in] Number of elements in pbHash. It should be no larger than 256.  
```  
***  


## Return value:
Returns S_OK (0) if successful, or a standard OLE error value otherwise.  
***  


## Comments:
See also UrlHash.  
See <A href="http://www.webopedia.com/TERM/H/hashing.html">Webopedia: Hashing</A>  
  
***  

