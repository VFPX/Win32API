[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptEncrypt
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Encrypts data. The algorithm used to encrypt the data is designated by the key held by the CSP module and is referenced by the hKey parameter.

***  


## Code examples:
[A class that encrypts and decrypts files using Cryptography API Functions](../../samples/sample_511.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptEncrypt(
	HCRYPTKEY hKey,
	HCRYPTHASH hHash,
	BOOL Final,
	DWORD dwFlags,
	BYTE* pbData,
	DWORD* pdwDataLen,
	DWORD dwBufLen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptEncrypt IN advapi32;
	INTEGER hKey,;
	INTEGER hHash,;
	INTEGER Final,;
	LONG dwFlags,;
	STRING @pbData,;
	LONG @pdwDataLen,;
	LONG dwBufLen
  
```  
***  


## Parameters:
hKey 
[in] The handle to the encryption key. An application obtains this handle by using either the CryptGenKey or the CryptImportKey function.

hHash 
[in] The handle to a hash object.

Final 
[in] A Boolean value that specifies whether this is the last section in a series being encrypted.

dwFlags
[in] Predefined value, can be zero.

pbData 
[in, out] A pointer to a buffer that contains the plaintext to be encrypted. The plaintext in this buffer is overwritten with the ciphertext created by this function.

pdwDataLen 
[in, out] A pointer to a DWORD value that , on entry, contains the length, in bytes, of the plaintext in the pbData buffer. On exit, this DWORD contains the length, in bytes, of the ciphertext written to the pbData buffer.

dwBufLen 
[in] Specifies the total size, in bytes, of the input pbData buffer.  
***  


## Return value:
If the function succeeds, the function returns TRUE.  
***  


## Comments:
If a large amount of data is to be encrypted, it can be done in sections by calling CryptEncrypt repeatedly. The Final parameter is set to TRUE on the last call to CryptEncrypt so that the encryption engine can properly finish the encryption process.  
  
***  

