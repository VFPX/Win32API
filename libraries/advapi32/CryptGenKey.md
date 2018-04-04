[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptGenKey
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Generates a random cryptographic session key or a public/private key pair. A handle to the key or key pair is returned in phKey. This handle can then be used as needed with any CryptoAPI function that requires a key handle.
***  


## Code examples:
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  
[Generating random cryptographic keys](../../samples/sample_590.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptGenKey(
	HCRYPTPROV hProv,
	ALG_ID Algid,
	DWORD dwFlags,
	HCRYPTKEY* phKey
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptGenKey IN advapi32;
	INTEGER   hProv,;
	INTEGER   Algid,;
	INTEGER   dwFlags,;
	INTEGER @ phKey
  
```  
***  


## Parameters:
hProv 
[in] Handle to a cryptographic service provider (CSP) created by a call to CryptAcquireContext.

Algid 
[in] A ALG_ID structure that identifies the algorithm for which the key is to be generated.

dwFlags 
[in] Specifies the type of key generated.

phKey 
[out] Address to which the function copies the handle of the newly generated key.  
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  


## Comments:
When you have finished using the key, delete the handle to the key by calling the CryptDestroyKey function.   
  
***  

