[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to retrieve list of system DSNs (Data Source Name) with parameters

## Short description:
The code shows how to use the SQLGetPrivateProfileString function to retrieve lists of current Data Sources (either System or User DSNs).  
***  


## Before you begin:
The code shows how to use the SQLGetPrivateProfileString function to retrieve lists of current Data Sources (either System or User DSNs).  

See also:

* [Enumerating ODBC Data Sources available on the local computer ](sample_284.md)  

  
***  


## Code:
```foxpro  
#DEFINE ODBC_BOTH_DSN   0  && BOTH may not work as expected
#DEFINE ODBC_USER_DSN   1
#DEFINE ODBC_SYSTEM_DSN 2
DO decl

LOCAL nConfigMode, cSources, cSource, cParamNames, cParam, ii, jj

* saving current value for SQLConfigMode
nConfigMode = GetConfigMode()
= SQLSetConfigMode(ODBC_SYSTEM_DSN)

cSources = Chr(0) + GetPS("ODBC Data Sources", Null) + Chr(0)
CREATE CURSOR csResult (odbcsource C(30), prmname C(20), prmvalue C(200))

ii=1
DO WHILE .T.
	cSource = GetSubstr(cSources, ii, Chr(0))
	IF EMPTY(cSource)
		EXIT
	ENDIF

	cParamNames = GetPS(cSource, Null)
	INSERT INTO csResult VALUES (cSource, "All parameters",;
		STRTRAN(cParamNames, Chr(0), " "))

	cParamNames = Chr(0) + GetPS(cSource, Null) + Chr(0)
	jj = 1
	DO WHILE .T.
		cParam = GetSubstr(cParamNames, jj, Chr(0))
		IF EMPTY(cParam)
			EXIT
		ENDIF
		= AddParam(cSource, cParam)
		jj = jj + 1
	ENDDO
	ii = ii + 1
ENDDO

* restoring SQLConfigMode value
= SQLSetConfigMode(m.nConfigMode)

GO TOP
BROWSE NORMAL NOWAIT
* end of main

PROCEDURE AddParam(cKey, pname)
	LOCAL pvalue
	pvalue = GetPS(cKey, m.pname)
	pvalue = STRTRAN(pvalue, Chr(0),"")
	IF Not EMPTY(pvalue)
		INSERT INTO csResult VALUES (m.cKey,;
			m.pname, m.pvalue)
	ENDIF

FUNCTION GetPS(section, entry)
	LOCAL cBuffer, nLen
	cBuffer = Repli(Chr(0), 250)
	nLen = SQLGetPrivateProfileString(section, entry, "",;
		@cBuffer, Len(cBuffer), "ODBC.INI")
RETURN Iif(nLen=0, "", SUBSTR(cBuffer, 1, nLen))

FUNCTION GetSubstr(cSource, nIndex, cChar)
	LOCAL nPos1, nPos2
	nPos1 = AT(cChar, cSource, nIndex)
	nPos2 = AT(cChar, cSource, nIndex+1)
	IF MIN(nPos1, nPos2) <> 0
		RETURN SUBSTR(cSource, nPos1+1, nPos2-nPos1-1)
	ENDIF
RETURN ""

FUNCTION GetConfigMode
	LOCAL nMode
	nMode=0
	= SQLGetConfigMode(@nMode)
RETURN m.nMode

PROCEDURE decl
	DECLARE INTEGER SQLSetConfigMode IN odbccp32 LONG wConfigMode
	DECLARE INTEGER SQLGetConfigMode IN odbccp32 LONG @pwConfigMode

	DECLARE INTEGER SQLGetPrivateProfileString IN odbccp32;
		STRING lpszSection, STRING lpszEntry, STRING lpszDefault,;
		STRING @RetBuffer, INTEGER cbRetBuffer, STRING lpszFilename  
```  
***  


## Listed functions:
[SQLGetConfigMode](../libraries/odbc32/SQLGetConfigMode.md)  
[SQLGetPrivateProfileString](../libraries/odbc32/SQLGetPrivateProfileString.md)  
[SQLSetConfigMode](../libraries/odbc32/SQLSetConfigMode.md)  
