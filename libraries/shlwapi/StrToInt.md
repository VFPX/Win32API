[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StrToInt
Group: [String](../../functions_group.md#String)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Converts a decimal string to an integer. The StrToLong macro differs from this function in name only.
***  


## Code examples:
[Converting a decimal string to an integer](../../samples/sample_106.md)  

## Declaration:
```foxpro  
int StrToInt(
    LPCTSTR lpSrc
    );

#define StrToLong StrToInt
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StrToInt IN Shlwapi STRING lpSrc
DECLARE INTEGER StrToLong IN Shlwapi STRING lpSrc  
```  
***  


## Parameters:
lpSrc 
Address of the null-terminated string to be converted.  
***  


## Return value:
Returns the INT value of a string.  
***  


## Comments:
See also: [StrToIntEx](../shlwapi/StrToIntEx.md), [StrToInt64Ex](..//StrToInt64Ex.md).  
  
Both functions work identically. The difference is 4 bytes for the INT and 8 bytes for the LONG.  
  
Native functions VAL and INT deliver quite sufficient functionality. Though another Win32 function from this family -- StrToIntEx -- gives a bit more.  
  
* * *  
When populating or parsing API structures, very often converting between 2, 4 and 8-byte strings to VFP numeric values and back is required.  
  
In VFP9, for converting between binary character representations and numbers use BINTOC() and CTOBIN() native VFP functions.  
  
In all VFP versions, for the same task use <Em>buf2word, buf2dword, num2word</Em> and <Em>num2dword</Em> functions.   
  
```foxpro
FUNCTION buf2dword(cBuffer)  
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;  
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;  
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;  
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
  
FUNCTION buf2word(lcBuffer)  
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;  
       Asc(SUBSTR(lcBuffer, 2,1)) * 256  
  
FUNCTION num2dword(lnValue)  
#DEFINE m0 0x0000100  
#DEFINE m1 0x0010000  
#DEFINE m2 0x1000000  
	IF lnValue < 0  
		lnValue = 0x100000000 + lnValue  
	ENDIF  
	LOCAL b0, b1, b2, b3  
	b3 = Int(lnValue/m2)  
	b2 = Int((lnValue - b3*m2)/m1)  
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)  
	b0 = Mod(lnValue, m0)  
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
  
FUNCTION num2word(lnValue)  
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))
```
Rarely a conversion to and from float binary representation is required. In this reference only a few GDI+ functions may need that.  
  
```foxpro
#DEFINE REAL_BIAS 127  
#DEFINE REAL_MANTISSA_SIZE 23  
#DEFINE REAL_NEGATIVE 0x80000000  
#DEFINE EXPONENT_MASK 0x7F800000  
#DEFINE MANTISSA_MASK 0x7FFFFF  
  
FUNCTION Float2Int(num)  
* converts 32-bit float form to FoxPro numeric  
	IF num = 0  
		RETURN 0  
	ENDIF  
	LOCAL sgn, exponent, mantissa  
	sgn = IIF(BITTEST(num,31), -1,1)  
	exponent = BITRSHIFT(BITAND(num, EXPONENT_MASK),;  
		REAL_MANTISSA_SIZE) - REAL_BIAS  
	mantissa = BITAND(num,;  
		MANTISSA_MASK) / 2^(REAL_MANTISSA_SIZE-exponent)  
RETURN (2^exponent + mantissa) * sgn  
  
FUNCTION Int2Float(num)  
* converts FoxPro numeric to 32-bit float form  
	LOCAL sgn, exponent, mantissa  
	DO CASE  
	CASE num < 0  
		sgn = REAL_NEGATIVE  
		num = -num  
	CASE num > 0  
		sgn = 0  
	OTHERWISE  
		RETURN 0  
	ENDCASE  
	exponent = FLOOR(LOG(num)/LOG(2))  
	mantissa = (num - 2^exponent)* 2^(REAL_MANTISSA_SIZE-exponent)  
	exponent = BITLSHIFT(exponent+REAL_BIAS, REAL_MANTISSA_SIZE)  
RETURN BITOR(sgn, exponent, mantissa)
```

***  

