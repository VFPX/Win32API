<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Converting a hexadecimal string to an integer

## Before you begin:
Check reverse example <a href="?example=260">Converting an integer value to a hexadecimal string</a>.[Converting an integer value to a hexadecimal string](sample_260.md)  
  
***  


## Code:
```foxpro  
#DEFINE STIF_DEFAULT               0
#DEFINE STIF_SUPPORT_HEX           1

DECLARE SHORT StrToIntEx IN Shlwapi;
	STRING    pszString,;
	INTEGER   dwFlags,;
	INTEGER @ pllRet

LOCAL lcHex, lnRet

lcHex = "0x800"
lnRet = 0

= StrToIntEx (lcHex, STIF_SUPPORT_HEX, @lnRet)
? lnRet  
```  
***  


## Listed functions:
[StrToIntEx](../libraries/shlwapi/StrToIntEx.md)  

## Comment:
STIF_DEFAULT mode supports regular decimal notation.  
  
***  

