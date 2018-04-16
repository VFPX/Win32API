[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Reading data from INI files

## Before you begin:
INI files are regular text files, except the data inside the file is structured.  

See also:

* [Writing to INI file](sample_137.md)  
* [Reading entries from Event logs](sample_524.md)  
* [Writing entries to custom Event Log](sample_564.md)  
  
***  


## Code:
```foxpro  
* select valid INI file
LOCAL lcFileName
lcFileName = GetWindowsDir() + "\winsight.ini"

CREATE CURSOR csResult (section C(50), keyname C(50),;
	keyvalue C(200))

lcSections = GetSections(lcFileName)
= str2cursor(lcSections, "csSections")

SELECT csSections
SCAN ALL
	SELECT csSections
	lcKeys = GetKeys(lcFileName, csSections.strvalue)
	= str2cursor(lcKeys, "csKeys")
	
	SELECT csKeys
	SCAN ALL
		lcValue = GetKeyValue(lcFileName,;
			csSections.strvalue, csKeys.strvalue)
		INSERT INTO csResult VALUES (;
			csSections.strvalue, csKeys.strvalue, lcValue)
	ENDSCAN
ENDSCAN

SELECT csResult
GO TOP
BROWSE NORMAL NOWAIT

FUNCTION GetSections(lcFileName)
	DECLARE INTEGER GetPrivateProfileString IN kernel32;
		INTEGER lpAppName, INTEGER lpKeyName,;
		STRING lpDefault, STRING @lpReturnedString,;
		INTEGER nSize, STRING lpFileName

	LOCAL lnSize, lpReturnedString, lnResult
	lnSize = 0x1000
	lpReturnedString = Repli(Chr(0), lnSize)
	
	lnResult = GetPrivateProfileString(0,0,;
		"#empty#", @lpReturnedString, lnSize,;
		lcFileName)
RETURN Left(lpReturnedString, lnResult)

FUNCTION GetKeys(lcFileName, lcSection)
	DECLARE INTEGER GetPrivateProfileString IN kernel32;
		STRING lpAppName, INTEGER lpKeyName,;
		STRING lpDefault, STRING @lpReturnedString,;
		INTEGER nSize, STRING lpFileName

	LOCAL lnSize, lpReturnedString, lnResult
	lnSize = 0x4000
	lpReturnedString = Repli(Chr(0), lnSize)
	
	lnResult = GetPrivateProfileString(lcSection,0,;
		"#empty#", @lpReturnedString, lnSize,;
		lcFileName)
RETURN Left(lpReturnedString, lnResult)

FUNCTION GetKeyValue(lcFileName, lcSection, lcKey)
	DECLARE INTEGER GetPrivateProfileString IN kernel32;
		STRING lpAppName, STRING lpKeyName,;
		STRING lpDefault, STRING @lpReturnedString,;
		INTEGER nSize, STRING lpFileName

	LOCAL lnSize, lpReturnedString, lnResult
	lnSize = 0x4000
	lpReturnedString = Repli(Chr(0), lnSize)
	
	lnResult = GetPrivateProfileString(lcSection, lcKey,;
		"#empty#", @lpReturnedString, lnSize,;
		lcFileName)
RETURN Left(lpReturnedString, lnResult)

FUNCTION str2cursor(lcSource, lcCursor)
* split zero-delimited string to substrings
* and save them in the given cursor

	CREATE CURSOR (lcCursor) (strvalue C(250))
	LOCAL ii, ch, ss, lnResult
	ss = ""
	lnResult = 0
	FOR ii=1 TO Len(lcSource)
		ch = SUBSTR(lcSource, ii,1)
		IF ch = Chr(0)
			INSERT INTO (lcCursor) VALUES (ss)
			lnResult = lnResult + 1
			ss = ""
		ELSE
			ss = ss + ch
		ENDIF
	ENDFOR
RETURN lnResult

FUNCTION GetWindowsDir
	DECLARE INTEGER GetWindowsDirectory IN kernel32;
		STRING @lpBuffer, INTEGER nSize

	lpBuffer = SPACE(250)
	nSizeRet = GetWindowsDirectory(@lpBuffer, Len(lpBuffer))
RETURN SUBSTR(lpBuffer, 1, nSizeRet)  
```  
***  


## Listed functions:
[GetPrivateProfileString](../libraries/kernel32/GetPrivateProfileString.md)  
[GetWindowsDirectory](../libraries/kernel32/GetWindowsDirectory.md)  

## Comment:
The target file should conform to the regular INI file format:  
```txt
[section]  
key=string  
...
```
  
Under some conditions this function applied to Win.Ini can read the corresponding Registry values instead the real file.  
  
Msdn: Calls to private profile functions may be mapped to the registry instead of to the specified initialization files.  
  
Apply this function to Win.Ini and check the results.  
  
***  

