[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StringFromGUID2
Group: [COM](../../functions_group.md#COM)  -  Library: [ole32](../../Libraries.md#ole32)  
***  


#### Converts a globally unique identifier (GUID) into a string of printable characters.
***  


## Code examples:
[Winsock: retrieving information about available transport protocols](../../samples/sample_223.md)  
[Custom GDI+ class](../../samples/sample_450.md)  
[How to generate GUID values](../../samples/sample_456.md)  
[Smart Card Database Query Functions](../../samples/sample_539.md)  
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  

## Declaration:
```foxpro  
int StringFromGUID2(
  REFGUID rguid,
  LPOLESTR lpsz,
  int cchMax
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StringFromGUID2 IN ole32;
	STRING    rguid,;
	STRING  @ lpsz,;
	INTEGER   cchMax
  
```  
***  


## Parameters:
rguid 
[in] GUID to be converted. 

lpsz 
[out] Pointer to a caller-allocated string variable to contain the resulting string on return. 

cchMax 
[in] Number of characters available in the buffer indicated by lpsz.  
***  


## Return value:
The number of characters in the returned string, including the null terminator or zero if the array at lpsz is too small to contain a string representation of a GUID.  
***  


## Comments:
The string that the <Em>lpsz</Em> parameter receives has a format like that of the following sample:  
{557cf400-1a04-11d3-9a73-0000f81ef32e}  
  
See also: [CLSIDFromString](../ole32/CLSIDFromString.md).  
  
***  

