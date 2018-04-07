[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptProtectData
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [crypt32](../../Libraries.md#crypt32)  
***  


#### Performs encryption on the data in a DATA_BLOB structure. Scoped to local computer, or to user credentials.
***  


## Declaration:
```foxpro  
BOOL WINAPI CryptProtectData(
  __in      DATA_BLOB *pDataIn,
  __in      LPCWSTR szDataDescr,
  __in      DATA_BLOB *pOptionalEntropy,
  __in      PVOID pvReserved,
  __in_opt  CRYPTPROTECT_PROMPTSTRUCT *pPromptStruct,
  __in      DWORD dwFlags,
  __out     DATA_BLOB *pDataOut
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptProtectData IN crypt32;
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
pDataIn [in]
A pointer to a DATA_BLOB structure that contains the plaintext to be encrypted.

szDataDescr [in]
A string with a readable description of the data to be encrypted.

pOptionalEntropy [in]
A pointer to a DATA_BLOB structure that contains a password or other additional entropy used to encrypt the data.

pvReserved [in]
Reserved for future use and must be set to NULL.

pPromptStruct [in, optional]
A pointer to a CRYPTPROTECT_PROMPTSTRUCT structure that provides information about where and when prompts are to be displayed.

dwFlags [in]
This parameter can be one of several predefined flags.

pDataOut [out]
A pointer to a DATA_BLOB structure that receives the encrypted data.  
***  


## Return value:
If the function succeeds, the function returns TRUE.  
***  


## Comments:
A user with a roaming profile can decrypt the data from another computer on the network.  
  
Otherwise, the encryption and decryption must be done on the same computer. Possibly can get even more limited, when only a user with the same logon credential as the user who encrypted the data can decrypt the data.   
  
When no longer required, the <Em>pbData</Em> member is to be freed by calling the LocalFree function.  
  
See also: [CryptUnprotectData](../crypt32/CryptUnprotectData.md), [CryptProtectMemory](..//CryptProtectMemory.md), [CryptUnprotectMemory](..//CryptUnprotectMemory.md).  
  
***  

