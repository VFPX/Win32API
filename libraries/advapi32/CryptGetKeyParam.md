[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptGetKeyParam
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves data that governs the operations of a key.
***  


## Code examples:
[CryptoAPI: Collection of Providers class](../../samples/sample_463.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptGetKeyParam(
	HCRYPTKEY hKey,
	DWORD dwParam,
	BYTE* pbData,
	DWORD* pdwDataLen,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptGetKeyParam IN advapi32;
	INTEGER   hKey,;
	INTEGER   dwParam,;
	STRING  @ pbData,;
	INTEGER @ pdwDataLen,;
	INTEGER   dwFlags
  
```  
***  


## Parameters:
hKey 
[in] Handle to the key being queried. 

dwParam 
[in] Specifies the query being made.

pbData 
[out] Pointer to a sequence of BYTEs to receive the data. 

pdwDataLen 
[in, out] Pointer to a DWORD value specifying the size, in bytes, of the buffer pointed to by the pbData parameter.

dwFlags 
[in] Reserved for future use and must be zero.   
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  


## Comments:
If the Microsoft Cryptographic Service Provider is used, the base symmetric keying material is not obtainable by this function or any other function.  
  
***  

