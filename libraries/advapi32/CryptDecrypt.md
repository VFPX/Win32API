[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptDecrypt
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Decrypts data previously encrypted using the CryptEncrypt function.
***  


## Code examples:
[A class that encrypts and decrypts files using Cryptography API Functions](../../samples/sample_511.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptDecrypt(
	HCRYPTKEY hKey,
	HCRYPTHASH hHash,
	BOOL Final,
	DWORD dwFlags,
	BYTE* pbData,
	DWORD* pdwDataLen
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptDecrypt IN advapi32;
	INTEGER hKey,;
	INTEGER hHash,;
	INTEGER Final,;
	LONG dwFlags,;
	STRING @pbData,;
	LONG @pdwDataLen
  
```  
***  


## Parameters:
hKey 
[in] Handle to the key to use for the decryption. An application obtains this handle by using either the CryptGenKey, CryptDeriveKey or CryptImportKey function. 

hHash 
[in] Handle to a hash object. If data is to be decrypted and hashed simultaneously, a handle to a hash object is passed in this parameter.

Final 
[in] Specifies whether this is the last section in a series being decrypted. This value is TRUE if this is the last or only block.

dwFlags 
[in] Currently not used.

pbData 
[in, out] Buffer that holds the data to be decrypted. After the decryption has been performed, the plaintext is placed back into this same buffer. 

pdwDataLen 
[in, out] Pointer to a DWORD value that indicates the length of the pbData buffer. Before calling this function, the calling application sets the DWORD value to the number of bytes to be decrypted.  
***  


## Return value:
If the function succeeds, the function returns nonzero (TRUE).  
***  


## Comments:
If a large amount of data is to be decrypted, it can be done in sections. This is done by calling CryptDecrypt repeatedly. The Final parameter must be set to TRUE only on the last call to CryptDecrypt, so the decryption engine can properly finish the decryption process.  
  
See also: [CryptEncrypt](../advapi32/CryptEncrypt.md), [CryptCreateHash](../advapi32/CryptCreateHash.md).  
  
***  

