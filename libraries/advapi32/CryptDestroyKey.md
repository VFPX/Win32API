[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptDestroyKey
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Releases the handle referenced by the hKey parameter. After a key handle has been released, it becomes invalid and cannot be used again.
***  


## Code examples:
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  
[A class that encrypts and decrypts files using Cryptography API Functions](../../samples/sample_511.md)  
[Generating random cryptographic keys](../../samples/sample_590.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptDestroyKey(
	HCRYPTKEY hKey
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptDestroyKey IN advapi32;
	INTEGER hKey  
```  
***  


## Parameters:
hKey 
[in] Handle of the key to be destroyed.  
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  


## Comments:
Keys take up both operating system"s memory space and the CSP"s memory space. Some CSPs are implemented in hardware with limited memory resources. Applications must destroy all keys with the CryptDestroyKey function when they are finished with them.  
  
***  

