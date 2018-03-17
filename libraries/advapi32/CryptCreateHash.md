<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CryptCreateHash
Group: Cryptography Reference - Library: advapi32    
***  


#### The CryptCreateHash function initiates the hashing of a stream of data. It creates and returns to the calling application a handle to a CSP hash object.
***  


## Code examples:
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  
[How to create MD-5 and SHA-1 hash values from a string](../../samples/sample_483.md)  
[A class that encrypts and decrypts files using Cryptography API Functions](../../samples/sample_511.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptCreateHash(
  HCRYPTPROV hProv,
  ALG_ID Algid,
  HCRYPTKEY hKey,
  DWORD dwFlags,
  HCRYPTHASH* phHash
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptCreateHash IN advapi32;
	INTEGER   hProv,;
	INTEGER   Algid,;
	INTEGER   hKey,;
	INTEGER   dwFlags,;
	INTEGER @ phHash
  
```  
***  


## Parameters:
```txt  
hProv
[in] Handle of a cryptographic service provider (CSP) created by a call to CryptAcquireContext.

Algid
[in] ALG_ID that identifies the hash algorithm to use.

hKey
[in] If the type of hash algorithm is a keyed hash, such as the HMAC or MAC algorithm, the key for the hash is passed in this parameter. For nonkeyed algorithms, this parameter must be set to zero.

dwFlags
[in] Reserved for future use and must be zero.

phHash
[out] Address to which the function copies a handle to the new hash object.  
```  
***  


## Return value:
If the function succeeds, the function returns TRUE.  
***  


## Comments:
The <Em>phHash</Em> handle is used in subsequent calls to CryptHashData and CryptHashSessionKey to hash session keys and other streams of data.  
  
When you have finished using the hash object, release the handle by calling the CryptDestroyHash function.   
  
***  

