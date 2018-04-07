[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StrFormatByteSize
Group: [String](../../functions_group.md#String)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Converts a numeric value into a string that represents the number expressed as a size value in bytes, kilobytes, megabytes, or gigabytes, depending on the size.
***  


## Code examples:
[String representation for disk or memory capacity](../../samples/sample_108.md)  

## Declaration:
```foxpro  
PSTR StrFormatByteSizeA(
         DWORD dw,
  __out  PSTR pszBuf,
         UINT cchBuf
);

PWSTR StrFormatByteSizeW(
         LONGLONG qdw,
  __out  PWSTR pszBuf,
         UINT cchBuf
);

PTSTR StrFormatByteSize64(
         LONGLONG qdw,
  __out  PTSTR pszBuf,
         UINT cchBuf
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE STRING StrFormatByteSizeA IN Shlwapi;
	INTEGER dw,;
	STRING @pszBuf,;
	INTEGER cchBuf
  
```  
***  


## Parameters:
dw / qdw 
[in] Numeric value to be converted. 

pszBuf / pwszBuf 
[out] Pointer to the converted string. 

cchBuf 
[in] Size of pszBuf, in characters. 
  
***  


## Return value:
Returns the address of the converted string, or NULL if the conversion fails.  
***  


## Comments:
See also: [StrFormatByteSize64](..//StrFormatByteSize64.md), [StrFormatByteSizeEx](..//StrFormatByteSizeEx.md), [StrFormatKBSize](..//StrFormatKBSize.md).  
  
***  

