<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CryptExportKey
Group: Cryptography Reference - Library: advapi32    
***  


#### Exports a cryptographic key or a key pair from a cryptographic service provider (CSP) in a secure manner.
***  


## Code examples:
[Generating random cryptographic keys](../../samples/sample_590.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptExportKey(
  _In_     HCRYPTKEY hKey,
  _In_     HCRYPTKEY hExpKey,
  _In_     DWORD dwBlobType,
  _In_     DWORD dwFlags,
  _Out_    BYTE *pbData,
  _Inout_  DWORD *pdwDataLen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptExportKey IN advapi32;
	INTEGER hKey,;
	INTEGER hExpKey,;
	INTEGER dwBlobType,;
	INTEGER dwFlags,;
	STRING @pbData,;
	INTEGER @pdwDataLen  
```  
***  


## Parameters:
```txt  
hKey [in]
A handle to the key to be exported.

hExpKey [in]
A handle to a cryptographic key of the destination user.

dwBlobType [in]
Specifies the type of key BLOB to be exported in pbData.

dwFlags [in]
Specifies additional options for the function.

pbData [out]
A pointer to a buffer that receives the key BLOB data.

pdwDataLen [in, out]
A pointer to a DWORD value that, on entry, contains the size, in bytes, of the buffer pointed to by the pbData parameter. When the function returns, this value contains the number of bytes stored in the buffer.  
```  
***  


## Return value:
If the function succeeds, the function returns nonzero (TRUE).  
***  


## Comments:
See also: CryptImportKey, CryptGenKey   
  
***  

