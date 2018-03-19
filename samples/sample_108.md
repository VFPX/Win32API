[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# String representation for disk or memory capacity

## Code:
```foxpro  
DECLARE STRING StrFormatByteSizeA IN Shlwapi;
   	INTEGER   dw,;
    STRING  @ pszBuf,;
	INTEGER   cchBuf

= _show (532)
= _show (1340)
= _show (23506)
= _show (2400016)
= _show (2400000000)

* notice that after 0xffffffff StrFormatByteSizeA
* does not return correct result
= _show (4294967295)	&& the largest size supported
= _show (4294967296)

FUNCTION  _show (dw)
	pszBuf = SPACE(50)
	? dw, " ->  "
	?? StrFormatByteSize (m.dw, @pszBuf, Len(pszBuf))  
```  
***  


## Listed functions:
[StrFormatByteSize](../libraries/shlwapi/StrFormatByteSize.md)  
