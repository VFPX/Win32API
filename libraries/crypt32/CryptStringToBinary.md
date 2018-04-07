[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptStringToBinary
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [crypt32](../../Libraries.md#crypt32)  
***  


#### Converts a formatted string into an array of bytes.
***  


## Code examples:
[How to perform Base64 encoding/decoding using Cryptography API Functions](../../samples/sample_088.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptStringToBinary(
	LPCTSTR pszString,
	DWORD cchString,
	DWORD dwFlags,
	BYTE* pbBinary,
	DWORD* pcbBinary,
	DWORD* pdwSkip,
	DWORD* pdwFlags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptStringToBinary IN crypt32;
	STRING @pszString,;
	LONG cchString,;
	LONG dwFlags,;
	STRING @pbBinary,;
	LONG @pcbBinary,;
	LONG pdwSkip,;
	LONG pdwFlags  
```  
***  


## Parameters:
pszString 
[in] A pointer to a string that contains the formatted string to be converted. 

cchString 
[in] The number of characters of the formatted string to be converted, not including the terminating NULL character. If this parameter is zero, pszString is considered to be a null-terminated string. 

dwFlags 
[in] Indicates the format of the string to be converted. 

pbBinary 
[in] A pointer to a buffer that receives the returned sequence of bytes.

pcbBinary 
[in, out] A pointer to a DWORD value that, on entry, contains the size, in bytes, of the pbBinary buffer.

pdwSkip 
[out] A pointer to a DWORD value that receives the number of characters skipped to reach the beginning of the actual base64 or hex strings. 

pdwFlags 
[out] A pointer to a DWORD value that receives the flags actually used in the conversion.   
***  


## Return value:
If the function succeeds, the return value is nonzero (TRUE).  
***  


## Comments:
Can be used for base64 decoding.  
  
See also: [CryptBinaryToString](../crypt32/CryptBinaryToString.md).  
  
***  

