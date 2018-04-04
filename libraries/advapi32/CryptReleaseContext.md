[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptReleaseContext
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The CryptReleaseContext function releases the handle of a cryptographic service provider (CSP) and a key container.
***  


## Code examples:
[How to fill a buffer with random bytes using Cryptography API Functions](../../samples/sample_053.md)  
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  
[How to create MD-5 and SHA-1 hash values from a string](../../samples/sample_483.md)  
[A class that encrypts and decrypts files using Cryptography API Functions](../../samples/sample_511.md)  
[Generating random cryptographic keys](../../samples/sample_590.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptReleaseContext(
  HCRYPTPROV hProv,
  DWORD dwFlags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptReleaseContext IN advapi32;
	INTEGER hProvHandle,;
	INTEGER nReserved
  
```  
***  


## Parameters:
hProv 
[in] Handle of a cryptographic service provider (CSP) created by a call to CryptAcquireContext. 

dwFlags 
[in] Reserved for future use and must be zero. If dwFlags is not set to zero, this function returns FALSE but the CSP is released.   
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  


## Comments:
At each call to this function, the reference count on the CSP is reduced by one. When the reference count reaches zero, the context is fully released and it can no longer be used by any function in the application.  
  
After this function has been called, the CSP session is finished and all existing session keys and hash objects created using the hProv handle become invalid. In practice, all of these objects should be destroyed with calls to CryptDestroyKey and CryptDestroyHash before CryptReleaseContext is called.  
  
***  

