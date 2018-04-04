[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptDeriveKey
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Generates cryptographic session keys derived from a base data value.
***  


## Code examples:
[A class that encrypts and decrypts files using Cryptography API Functions](../../samples/sample_511.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptDeriveKey(
	HCRYPTPROV hProv,
	ALG_ID Algid,
	HCRYPTHASH hBaseData,
	DWORD dwFlags,
	HCRYPTKEY* phKey
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptDeriveKey IN advapi32;
	INTEGER hProv,;
	INTEGER Algid,;
	INTEGER hBaseData,;
	LONG dwFlags,;
	INTEGER @phKey  
```  
***  


## Parameters:
hProv 
[in] A HCRYPTPROV handle of a CSP created by a call to CryptAcquireContext. 

Algid 
[in] An ALG_ID structure that identifies the symmetric encryption algorithm for which the key is to be generated. 

hBaseData 
[in] Handle to a hash object that has been fed the exact base data.

dwFlags 
[in] Specifies the type of key generated.

phKey 
[in, out] Address to which the function copies the handle of the newly generated key. When you have finished using the key, release the handle by calling the CryptDestroyKey function.   
***  


## Return value:
If the function succeeds, the function returns nonzero (TRUE).  
***  

