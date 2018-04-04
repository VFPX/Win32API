[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptAcquireContext
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The CryptAcquireContext function is used to acquire a handle to a particular key container within a particular cryptographic service provider (CSP). This returned handle is used in calls to CryptoAPI functions that use the selected CSP.
***  


## Code examples:
[How to fill a buffer with random bytes using Cryptography API Functions](../../samples/sample_053.md)  
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  
[How to create MD-5 and SHA-1 hash values from a string](../../samples/sample_483.md)  
[A class that encrypts and decrypts files using Cryptography API Functions](../../samples/sample_511.md)  
[Generating random cryptographic keys](../../samples/sample_590.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptAcquireContext(
  HCRYPTPROV* phProv,
  LPCTSTR pszContainer,
  LPCTSTR pszProvider,
  DWORD dwProvType,
  DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptAcquireContext IN advapi32;
	INTEGER @ hProvHandle,;
	STRING    cContainer, ;
	STRING    cProvider,;
	INTEGER   nProvType,;
	INTEGER   nFlags
  
```  
***  


## Parameters:
phProv 
[out] Pointer to a handle of a CSP.  

pszContainer 
[in] Key container name. 

pszProvider 
[in] A null-terminated string that specifies the name of the CSP to be used. 

dwProvType 
[in] Specifies the type of provider to acquire.

dwFlags 
[in] Flag values.  
***  


## Return value:
If the function succeeds, the function returns nonzero (TRUE).  
***  


## Comments:
When you have finished using the CSP, release the handle by calling the CryptReleaseContext function.  
  
***  

