[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HashData
Group: [Shell Lightweight Utility APIs -- misc. functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_misc._functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
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
pbData 
[in] Pointer to the data array. 

cbData 
[in] Number of elements in pbData. 

pbHash 
[out] Value used to return the hashed array. 

cbHash 
[in] Number of elements in pbHash. It should be no larger than 256.  
***  


## Return value:
Returns S_OK (0) if successful, or a standard OLE error value otherwise.  
***  


## Comments:
See also: [UrlHash](UrlHash.md ).  

***  

