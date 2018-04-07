[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptImportKey
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Transfers a cryptographic key from a key BLOB into a cryptographic service provider (CSP).
***  


## Code examples:
[Generating random cryptographic keys](../../samples/sample_590.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptImportKey(
  _In_   HCRYPTPROV hProv,
  _In_   BYTE *pbData,
  _In_   DWORD dwDataLen,
  _In_   HCRYPTKEY hPubKey,
  _In_   DWORD dwFlags,
  _Out_  HCRYPTKEY *phKey
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptImportKey IN advapi32;
	INTEGER hProv,;
	STRING @pbData,;
	INTEGER dwDataLen,;
	INTEGER hPubKey,;
	INTEGER dwFlags,;
	INTEGER @phKey  
```  
***  


## Parameters:
hProv [in]
The handle of a CSP obtained with the CryptAcquireContext function.

pbData [in]
A BYTE array that contains a <a href="http://msdn.microsoft.com/en-us/library/windows/desktop/aa387453(v=vs.85).aspx">PUBLICKEYSTRUC BLOB header</a> followed by the encrypted key.

dwDataLen [in]
Contains the length, in bytes, of the key BLOB.

hPubKey [in]
A handle to the cryptographic key that decrypts the key stored in pbData. 

dwFlags [in]
Currently used only when a public/private key pair in the form of a PRIVATEKEYBLOB is imported into the CSP.

phKey [out]
A pointer to a HCRYPTKEY value that receives the handle of the imported key.  
***  


## Return value:
If the function succeeds, the function returns nonzero.  
***  


## Comments:
When you have finished using the key, release the handle by calling the CryptDestroyKey function.  
  
See also: [CryptGenKey](../advapi32/CryptGenKey.md), [CryptExportKey](../advapi32/CryptExportKey.md).  
  
***  

