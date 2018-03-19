[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Analyzing character types in a specified string

## Code:
```foxpro  
LOCAL oStringType as StringType
oStringType = CREATEOBJECT("StringType", "123")

? oStringType.IsPrintable()
* end of main

DEFINE CLASS StringType As Relation
#DEFINE LOCALE_CUSTOM_DEFAULT 0x0C00
#DEFINE LOCALE_CUSTOM_UI_DEFAULT 0x1400
#DEFINE LOCALE_CUSTOM_UNSPECIFIED 0x1000

#DEFINE LOCALE_INVARIANT 0x007F
#DEFINE LOCALE_SYSTEM_DEFAULT 0x0800
#DEFINE LOCALE_USER_DEFAULT 0x0400

#DEFINE CT_CTYPE1 1 && character type
#DEFINE CT_CTYPE2 2 && bidirectional layout
#DEFINE CT_CTYPE3 3 && text processing

#DEFINE C1_UPPER 0x0001 && Uppercase
#DEFINE C1_LOWER 0x0002 && Lowercase
#DEFINE C1_DIGIT 0x0004 && Decimal digits
#DEFINE C1_SPACE 0x0008 && Space characters
#DEFINE C1_PUNCT 0x0010 && Punctuation
#DEFINE C1_CNTRL 0x0020 && Control characters
#DEFINE C1_BLANK 0x0040 && Blank characters
#DEFINE C1_XDIGIT 0x0080 && Hexadecimal digits
#DEFINE C1_ALPHA 0x0100 && Any linguistic character
#DEFINE C1_DEFINED 0x0200 && A defined character, but not one of the other C1_* types

	CharTypes=NULL

PROCEDURE Init(cSource as String)
	DECLARE INTEGER GetStringTypeEx IN kernel32;
		INTEGER Locale, INTEGER dwInfoType,;
		STRING lpSrcStr, INTEGER cchSrc,;
		STRING @lpCharType

	LOCAL cCharTypes, nIndex
	cCharTypes = REPLICATE(CHR(0), LEN(m.cSource) * 2) + 2

	= GetStringTypeEx(;
		LOCALE_SYSTEM_DEFAULT,;
		CT_CTYPE1,;
		m.cSource,;
		LEN(m.cSource),;
		@cCharTypes;
		)

	THIS.CharTypes = CREATEOBJECT("Collection")
	
	FOR m.nIndex = 1 TO LEN(m.cCharTypes) STEP 2
		cBuffer = SUBSTR(m.cCharTypes, m.nIndex, 2)
		nValue = buf2word(m.cBuffer)
		THIS.CharTypes.Add(m.nValue)
	NEXT

FUNCTION IsNumeric(cCharTypes as String) as Boolean
	LOCAL nValue
	FOR EACH nValue IN THIS.CharTypes
		IF nValue = 0 OR BITAND(m.nValue, C1_DIGIT) = 0
			RETURN .F.
		ENDIF
	NEXT
RETURN .T.

FUNCTION IsPrintable(cCharTypes as String) as Boolean
	LOCAL nValue
	FOR EACH nValue IN THIS.CharTypes
		IF BITAND(m.nValue, C1_CNTRL) <> 0
			RETURN .F.
		ENDIF
	NEXT
RETURN .T.

ENDDEFINE  
```  
***  


## Listed functions:
[GetStringTypeEx](../libraries/kernel32/GetStringTypeEx.md)  
