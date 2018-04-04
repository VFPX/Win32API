[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptHashData
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Adds data to a specified hash object.

***  


## Code examples:
[How to create MD-5 and SHA-1 hash values from a string](../../samples/sample_483.md)  
[A class that encrypts and decrypts files using Cryptography API Functions](../../samples/sample_511.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptHashData(
	HCRYPTHASH hHash,
	BYTE* pbData,
	DWORD dwDataLen,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptHashData IN advapi32;
	INTEGER  hHash,;
	STRING @ pbData,;
	LONG     dwDataLen,;
	LONG     dwFlags
  
```  
***  


## Parameters:
hHash 
[in] Handle of the hash object. 

pbData 
[in] Pointer to a buffer containing the data to be added to the hash object. 

dwDataLen 
[in] Number of bytes of data to be added. This must be zero if the CRYPT_USERDATA flag is set. 

dwFlags 
[in] Ignore.  
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
This function and CryptHashSessionKey can be called multiple times to compute the hash of long or discontinuous data streams.  
  
***  

