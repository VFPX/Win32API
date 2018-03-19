
# Converting an integer value to a hexadecimal string

## Before you begin:
Check reverse example <a href="?example=107">Converting a hexadecimal string to an integer</a>.[Converting a hexadecimal string to an integer](sample_107.md)  
  
***  


## Code:
```foxpro  
? int2hex(100)

FUNCTION  int2hex (num)
	DECLARE INTEGER wnsprintf IN Shlwapi;
		STRING @lpOut, INTEGER cchLimitIn,;
		STRING pszFmt, INTEGER

	LOCAL lnResult, lcResult
	lcResult = SPACE(20)
	lnResult = wnsprintf(@lcResult, 20, "%x", num)
RETURN Left(lcResult, lnResult)  
```  
***  


## Listed functions:
[wnsprintf](../libraries/shlwapi/wnsprintf.md)  

## Comment:
This can also be done with:  
**TRANSFORM(num, "@0")**  
not including VFP3.  
  
***  

