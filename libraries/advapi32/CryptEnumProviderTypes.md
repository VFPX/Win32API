[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptEnumProviderTypes
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves the first or next types of cryptographic service provider (CSP) supported on the computer. Used in a loop, this function retrieves in sequence all of the CSP types available on a computer.

***  


## Code examples:
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptEnumProviderTypes(
	DWORD dwIndex,
	DWORD* pdwReserved,
	DWORD dwFlags,
	DWORD* pdwProvType,
	LPTSTR pszTypeName,
	DWORD* pcbTypeName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptEnumProviderTypes IN advapi32;
	INTEGER   dwIndex,;
	INTEGER   pdwReserved,;
	INTEGER   dwFlags,;
	INTEGER @ pdwProvType,;
	STRING  @ pszTypeName,;
	INTEGER @ pcbTypeName
  
```  
***  


## Parameters:
dwIndex 
[in] Index of the next provider type to be enumerated. 

pdwReserved 
[in] Reserved for future use and must be NULL. 

dwFlags 
[in] Reserved for future use and must be zero. 

pdwProvType 
[out] Address of the DWORD value designating the enumerated provider type. 

pszTypeName 
[out] Pointer to a buffer that receives the data from the enumerated provider type.

pcbTypeName 
[in, out] Pointer to a DWORD value specifying the size, in bytes, of the buffer pointed to by the pszTypeName parameter.  
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  

