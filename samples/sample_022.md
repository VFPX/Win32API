[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# OS version and revision

## Code:
```foxpro  
DECLARE INTEGER GetVersion IN kernel32

DECLARE SHORT StrToIntEx IN Shlwapi;
	STRING pszString, INTEGER dwFlags, INTEGER @pllRet

lnVersion = GetVersion()

* The low-order word
lnVersionLo = BitRShift(BitLShift(lnVersion, 16), 16)
? "Major Version: ", BitAnd(lnVersionLo, hex2dec("0x00ff"))
? "Minor Version: ", BitRShift(BitAnd(lnVersionLo, hex2dec("0xff00")), 8)
?

* The high-order word
lnVersionHi = BitRShift(BitAnd(lnVersion, hex2dec("0xffff0000")), 16)
? lnVersionHi

FUNCTION  hex2dec (lcHex)
#DEFINE STIF_SUPPORT_HEX           1
	LOCAL lnRet
	lnRet = 0
	IF StrToIntEx (lcHex, STIF_SUPPORT_HEX, @lnRet) = 1
		RETURN lnRet
	ELSE
		RETURN 0
	ENDIF  
```  
***  


## Listed functions:
[GetVersion](../libraries/kernel32/GetVersion.md)  
[StrToIntEx](../libraries/shlwapi/StrToIntEx.md)  
