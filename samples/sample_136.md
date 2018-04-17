[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Reading keys in the specified section of the Win.ini file

## Before you begin:
Determine that Simple MAPI is available by checking the [MAIL] section in the computer"s WIN.INI file for the MAPI entry. This entry will have a value of 1 if Simple MAPI is installed, or 0 if uninstalled:  

![](../images/mapiavail.jpg)  
  
***  


## Code:
```foxpro  
*lcSection = "Windows"  && section name
lcSection = "Mail"  && section name

lcKeys = getKeysString (lcSection)

CREATE CURSOR csWinIni (keyname C(30), keyvalue C(200))

lcKey = ""
FOR ii=1 TO Len(lcKeys)
	ch = SUBSTR (lcKeys, ii,1)
	IF ch = Chr(0)
		lcValue = GetKeyValue(lcSection, lcKey)
		INSERT INTO csWinIni VALUES (lcKey, lcValue)
		lcKey = ""
	ELSE
		lcKey = lcKey + ch
	ENDIF
ENDFOR

SELECT csWinIni
GO TOP
BROW NORMAL NOWAIT

FUNCTION  getKeysString (lcSection)
* returns all key names found in this section
* delimited with zero character

	* Notice that lpKeyName declared as INTEGER
	* to emulate an empty key name

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING   lpAppName,;
		INTEGER  lpKeyName,;
		STRING   lpDefault,;
		STRING @ lpReturnedString,;
		INTEGER  nSize

	nSize = 1024
	lpReturnedString = Repli (Chr(0), nSize)

	lnResult = GetProfileString (lcSection, 0, "#empty#",;
		@lpReturnedString, nSize)
RETURN  Left(lpReturnedString, lnResult)

FUNCTION  GetKeyValue (lcSection, lcKey)

	* Notice that lpKeyName declared as STRING
	* because here we have a string value
	* supplied to this procedure

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING   lpAppName,;
		STRING   lpKeyName,;
		STRING   lpDefault,;
		STRING @ lpReturnedString,;
		INTEGER  nSize

	nSize = 4096
	lpReturnedString = Repli (Chr(0), nSize)

	lnResult = GetProfileString (lcSection, lcKey, "#empty#",;
		@lpReturnedString, nSize)
RETURN  Left(lpReturnedString, lnResult)  
```  
***  


## Listed functions:
[GetProfileString](../libraries/kernel32/GetProfileString.md)  

## Comment:

A section in the Win.ini file must have the following form:  
```txt
[section]  
key=string
```

***  

