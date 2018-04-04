[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptGetHashParam
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves data that governs the operations of a hash object. The actual hash value can be retrieved by using this function.

***  


## Code examples:
[How to create MD-5 and SHA-1 hash values from a string](../../samples/sample_483.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptGetHashParam(
	HCRYPTHASH hHash,
	DWORD dwParam,
	BYTE* pbData,
	DWORD* pdwDataLen,
	DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptGetHashParam IN advapi32;
	INTEGER  hHash,;
	LONG     dwParam,;
	STRING @ pbData,;
	LONG   @ pdwDataLen,;
	LONG     dwFlags  
```  
***  


## Parameters:
hHash 
[in] Handle of the hash object to be queried. 

dwParam 
[in] Query type.

pbData 
[out] Pointer to a buffer that receives the specified value data.

pdwDataLen 
[in, out] Pointer to a DWORD value specifying the size, in bytes, of the pbData buffer. 

dwFlags 
[in] Reserved for future use and must be zero.   
***  


## Return value:
If the function succeeds, the return value is TRUE.  
***  


## Comments:
Parameter <Em>pbData</Em> can be NULL to determine the memory size required.  
  
***  

