[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CryptBinaryToString
Group: [Cryptography Reference](../../functions_group.md#Cryptography_Reference)  -  Library: [crypt32](../../Libraries.md#crypt32)  
***  


#### Converts an array of bytes into a formatted string.
***  


## Code examples:
[How to perform Base64 encoding/decoding using Cryptography API Functions](../../samples/sample_088.md)  

## Declaration:
```foxpro  
BOOL WINAPI CryptBinaryToString(
	const BYTE* pbBinary,
	DWORD cbBinary,
	DWORD dwFlags,
	LPTSTR pszString,
	DWORD* pcchString
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CryptBinaryToString IN Crypt32;
	STRING @pbBinary,;
	LONG cbBinary,;
	LONG dwFlags,;
	STRING @pszString,;
	LONG @pcchString  
```  
***  


## Parameters:
pbBinary 
[in] A pointer to the array of bytes to be converted into a string. 

cbBinary 
[in] The number of elements in the pbBinary array. 

dwFlags 
[in] Specifies the format of the resulting formatted string.

pszString 
[in] A pointer to a buffer that receives the converted string.

pcchString 
[in, out] A pointer to a DWORD variable that contains the size, in TCHARs, of the pszString buffer.   
***  


## Return value:
If the function succeeds, the function returns nonzero (TRUE).  
***  


## Comments:
Can be used for base64 encoding.  
  
See also: [CryptStringToBinary](../crypt32/CryptStringToBinary.md).  
  
This is the output of CryptBinaryToString with <Em>dwFlags</Em> set to CRYPT_STRING_HEXASCIIADDR (0x000b).  

![](../../images/crypt_string_hex.png)

***  

