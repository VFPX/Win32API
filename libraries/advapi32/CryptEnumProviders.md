[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptEnumProviders
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves the first or next available cryptographic service providers (CSPs). Used in a loop, this function can retrieve in sequence all of the CSPs available on a computer.
***  


## Code examples:
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptEnumProviders(
	DWORD dwIndex,
	DWORD* pdwReserved,
	DWORD dwFlags,
	DWORD* pdwProvType,
	LPTSTR pszProvName,
	DWORD* pcbProvName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptEnumProviders IN advapi32;
	INTEGER   dwIndex,;
	INTEGER   pdwReserved,;
	INTEGER   dwFlags,;
	INTEGER @ pdwProvType,;
	STRING  @ pszProvName,;
	INTEGER @ pcbProvName
  
```  
***  


## Parameters:
dwIndex 
[in] Index of the next provider to be enumerated. 

pdwReserved 
[in] Reserved for future use and must be NULL. 

dwFlags 
[in] Reserved for future use and must be zero. 

pdwProvType 
[out] Address of the DWORD value designating the type of the enumerated provider. 

pszProvName 
[out] Pointer to a buffer that receives the data from the enumerated provider.

pcbProvName 
[in, out] Pointer to a DWORD value specifying the size, in bytes, of the buffer pointed to by the pszProvName parameter.  
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  


## Comments:
Possible CSPs include Microsoft Base Cryptographic Provider version 1.0 and Microsoft Enhanced Cryptographic Provider version 1.0.  
  
***  

