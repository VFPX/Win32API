[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving a universal form for the drive-based path for a network resource

## Code:
```foxpro  
DO decl

#DEFINE UNIVERSAL_NAME_INFO_LEVEL 1
#DEFINE REMOTE_NAME_INFO_LEVEL    2
#DEFINE NO_ERROR                  0

LOCAL lcPath, lnLevel, lcBuffer, lnBufsize, lnResult
lcPath = "z:\"
lnBufsize = 250
lcBuffer = Repli(Chr(0), lnBufsize)

lnLevel = UNIVERSAL_NAME_INFO_LEVEL
*lnLevel = REMOTE_NAME_INFO_LEVEL

lnResult = WNetGetUniversalName (lcPath, lnLevel,;
	@lcBuffer, @lnBufsize)

IF lnResult <> NO_ERROR
*   50 - ERROR_NOT_SUPPORTED
*  234 - ERROR_MORE_DATA
* 1200 - ERROR_BAD_DEVICE
* 1201 - ERROR_CONNECTION_UNAVAIL
* 1203 - ERROR_NO_NET_OR_BAD_PATH
* 1208 - ERROR_EXTENDED_ERROR
* 1222 - ERROR_NO_NETWORK
* 2250 - ERROR_NOT_CONNECTED

	IF lnResult = 1208 && ERROR_EXTENDED_ERROR
		? "Extended error: ", GetXError()
	ELSE
		? "Error code:", lnResult
	ENDIF
ELSE
	DO WHILE Right(lcBuffer,1) = Chr(0) And Len(lcBuffer) > 2
		lcBuffer = Left(lcBuffer, Len(lcBuffer)-1)
	ENDDO

	LOCAL ii, ch

	CREATE CURSOR csResult (asc N(5), ch C(1))
	FOR ii=1 TO Len(lcBuffer)
		ch = SUBSTR(lcBuffer, ii,1)
		INSERT INTO csResult VALUES (Asc(m.ch), m.ch)
	ENDFOR

	GO TOP
	BROWSE NORMAL NOWAIT
ENDIF

FUNCTION GetXError
	LOCAL lnErrCode, lcErrDescr, lcProvider, lnResult
	lnErrCode = 0
	STORE Repli(Chr(0),250) TO lcErrDescr, lcProvider

	lnResult = WNetGetLastError (@lnErrCode,;
		@lcErrDescr, Len(lcErrDescr),;
		@lcProvider, Len(lcProvider))

	IF lnResult = NO_ERROR
		RETURN LTRIM(STR(lnErrCode)) + ". " +;
			ALLTRIM(STRTRAN(lcErrDescr, Chr(0),""))
	ENDIF
RETURN "???"

PROCEDURE decl
	DECLARE INTEGER WNetGetUniversalName IN mpr;
		STRING lpLocalPath, INTEGER dwInfoLevel,;
		STRING @lpBuffer, INTEGER @lpBufferSize

	DECLARE INTEGER WNetGetLastError IN mpr;
		INTEGER @lpError, STRING @lpErrorBuf,;
		INTEGER nErrorBufSize, STRING @lpNameBuf,;
		INTEGER nNameBufSize

*|typedef struct _UNIVERSAL_NAME_INFO {
*|  LPTSTR  lpUniversalName;
*|} UNIVERSAL_NAME_INFO;

*|typedef struct _REMOTE_NAME_INFO {
*|  LPTSTR  lpUniversalName;
*|  LPTSTR  lpConnectionName;
*|  LPTSTR  lpRemainingPath;
*|} REMOTE_NAME_INFO;  
```  
***  


## Listed functions:
[WNetGetLastError](../libraries/odbc32/WNetGetLastError.md)  
[WNetGetUniversalName](../libraries/mpr/WNetGetUniversalName.md)  
