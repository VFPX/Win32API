<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CryptUnprotectData
Group: Cryptography Reference - Library: crypt32    
***  


#### Decrypts and does an integrity check of the data in a DATA_BLOB structure. Scoped to local computer, or to user credentials.
***  


## Declaration:
```foxpro  
BOOL WINAPI CryptUnprotectData(
  __in       DATA_BLOB *pDataIn,
  __out_opt  LPWSTR *ppszDataDescr,
  __in_opt   DATA_BLOB *pOptionalEntropy,
  __in       PVOID pvReserved,
  __in_opt   CRYPTPROTECT_PROMPTSTRUCT *pPromptStruct,
  __in       DWORD dwFlags,
  __out      DATA_BLOB *pDataOut
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptUnprotectData IN crypt32;
	INTEGER pDataIn,;
	STRING szDataDescr,;
	INTEGER pOptionalEntropy,;
	INTEGER pvReserved,;
	STRING @pPromptStruct,;
	LONG dwFlags,;
	INTEGER @pDataOut  
```  
***  


## Parameters:
```txt  
pDataIn [in]
A pointer to a DATA_BLOB structure that holds the encrypted data.

ppszDataDescr [out, optional]
A pointer to a string-readable description of the encrypted data included with the encrypted data.

pOptionalEntropy [in, optional]
A pointer to a DATA_BLOB structure that contains a password or other additional entropy used when the data was encrypted.

pPromptStruct [in, optional]
A pointer to a CRYPTPROTECT_PROMPTSTRUCT structure that provides information about where and when prompts are to be displayed.

dwFlags [in]
This parameter can be one of several predefined flags.

pDataOut [out]
A pointer to a DATA_BLOB structure that receives the decrypted data.  
```  
***  


## Return value:
If the function succeeds, the function returns TRUE.  
***  


## Comments:
When you have finished using sensitive information, clear it from memory by calling the SecureZeroMemory function.  
  
See also: CryptProtectData, CryptProtectMemory, CryptUnprotectMemory    
  
***  

