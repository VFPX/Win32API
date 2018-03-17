<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CryptGetProvParam
Group: Cryptography Reference - Library: advapi32    
***  


#### Retrieves parameters that govern the operations of a cryptographic service provider (CSP).
***  


## Code examples:
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptGetProvParam(
  HCRYPTPROV hProv,
  DWORD dwParam,
  BYTE* pbData,
  DWORD* pdwDataLen,
  DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptGetProvParam IN advapi32;
	INTEGER   hProv,;
	INTEGER   dwParam,;
	STRING  @ pbData,;
	INTEGER @ pdwDataLen,;
	INTEGER   dwFlags
  
```  
***  


## Parameters:
```txt  
hProv
[in] Handle of the CSP target of the query. This handle must have been created using CryptAcquireContext.

dwParam
[in] Predefined value specifying the nature of the query.

pbData
[out] Pointer to a buffer to receive the data. The form of this data varies depending on the value of dwParam.

pdwDataLen
[in, out] Pointer to a DWORD value specifying the size, in bytes, of the buffer pointed to by the pbData parameter.

dwFlags
[in] Flag values.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  

