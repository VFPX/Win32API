[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Establishing connection using the SQLDriverConnect

## Code:
```foxpro  
#DEFINE SQL_SUCCESS 0
#DEFINE SQL_SUCCESS_WITH_INFO 1
#DEFINE SQL_HANDLE_DBC 2
#DEFINE SQL_DRIVER_NOPROMPT 0
#DEFINE SQL_DRIVER_PROMPT 2
#DEFINE SQL_DRIVER_COMPLETE 1
#DEFINE SQL_DRIVER_COMPLETE_REQUIRED  3
DO declare

PRIVATE hEnv, hConn
STORE 0 TO hEnv, hConn

= SQLAllocEnv(@hEnv)
= SQLAllocHandle(SQL_HANDLE_DBC, hEnv, @hConn)

? GetConnected("", SQL_DRIVER_PROMPT)

*!*	? GetConnected("Driver={SQL Server}", SQL_DRIVER_PROMPT)
*!*	? GetConnected("DSN=Visual FoxPro Database", SQL_DRIVER_PROMPT)
*!*	? GetConnected("DSN=ECDCMusic", SQL_DRIVER_NOPROMPT)

*!*	? GetConnected("DSN=Visual FoxPro Database;SourceDB=c:\mydata",;
*!*		SQL_DRIVER_NOPROMPT)

*!*	? GetConnected("DSN=Excel Files;DBQ=c:\Excel\test.xls",;
*!*		SQL_DRIVER_NOPROMPT)

*!*	? GetConnected("DRIVER=SQL Server;SERVER=sql.someserver.com,1433;" +;
*!*		"UID=sqluser;PWD=xxxxx;", SQL_DRIVER_NOPROMPT)

DO GetDisconnect
* end of main

FUNCTION GetConnected(lcConnect, lnCompletion)
	LOCAL lcSavedPath, hWindow, lcBuffer, lnBuflen, lcResult
	lcSavedPath = FULLPATH("")
	lcBuffer = Repli(Chr(0), 250)
	lnBuflen = 0
	hWindow = GetActiveWindow()  && window handle

	? "SQLDriverConnect:", SQLDriverConnect(hConn, hWindow,;
		lcConnect, Len(lcConnect), @lcBuffer, Len(lcBuffer),;
		@lnBuflen, lnCompletion)
	?

	IF lnBuflen = 0
		= GetDiagRecs(hConn, SQL_HANDLE_DBC)
		lcResult = ""
	ELSE
		lcResult = Left(lcBuffer, lnBuflen)
	ENDIF
	SET DEFAULT TO (lcSavedPath)
RETURN lcResult

PROCEDURE GetDiagRecs(lnHandle, lnHandleType)
* printing diag records
	LOCAL lnRecno, lcSQLState, lnNativeError,;
		lcMessage, lnMsgLen, lnResult

	? "Diag records:"
	lnRecno = 1
	DO WHILE .T.
		lcSQLState = SPACE(5)
		STORE 0 TO lnNativeError, lnMsgLen
		lcMessage = SPACE(250)

		lnResult = SQLGetDiagRec(lnHandleType, lnHandle, lnRecno,;
			@lcSQLState, @lnNativeError,;
			@lcMessage, Len(lcMessage), @lnMsgLen)

		IF INLIST(lnResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
			? lcSQLState, "|", lnNativeError, "|", Left(lcMessage, lnMsgLen)
			lnRecno = lnRecno + 1
		ELSE
			EXIT
		ENDIF
	ENDDO
RETURN

PROCEDURE GetDisconnect
	IF hConn <> 0
		= SQLDisconnect32(hConn)
		= SQLFreeHandle(SQL_HANDLE_DBC, hConn)
	ENDIF
	IF hEnv <> 0
		= SQLFreeEnv(hEnv)
	ENDIF
RETURN

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32

	DECLARE SHORT SQLDriverConnect IN odbc32;
		INTEGER ConnHandle, INTEGER WinHandle, STRING InConnStr,;
		SHORT StrLen1, STRING @OutConnStr, SHORT BufLen,;
		SHORT @StrLen2Ptr, INTEGER DriverCompletion

	DECLARE SHORT SQLAllocEnv IN odbc32 INTEGER @env
	DECLARE SHORT SQLFreeEnv IN odbc32 INTEGER env

	DECLARE SHORT SQLFreeHandle IN odbc32;
		INTEGER HandleType, INTEGER Handle

	DECLARE SHORT SQLAllocHandle IN odbc32;
		INTEGER HandleType, INTEGER InputHandle,;
		INTEGER @OutputHandlePtr

	DECLARE SHORT SQLConnect IN odbc32 AS SQLConnect32;
		INTEGER ConnHandle, STRING ServerName, INTEGER NameLen1,;
		STRING UserName, INTEGER NameLen2, STRING Authentication,;
		INTEGER NameLen3

	DECLARE SHORT SQLDisconnect IN odbc32 AS SQLDisconnect32;
		INTEGER ConnectionHandle

	DECLARE SHORT SQLGetDiagRec IN odbc32;
		INTEGER HandleType, INTEGER Handle, INTEGER RecNumber,;
		STRING @Sqlstate, INTEGER @NativeErrorPtr, STRING @MsgText,;
		INTEGER BufferLength, INTEGER @TextLengthPtr  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[SQLAllocEnv](../libraries/odbc32/SQLAllocEnv.md)  
[SQLAllocHandle](../libraries/odbc32/SQLAllocHandle.md)  
[SQLConnect](../libraries/odbc32/SQLConnect.md)  
[SQLDisconnect](../libraries/odbc32/SQLDisconnect.md)  
[SQLDriverConnect](../libraries/odbc32/SQLDriverConnect.md)  
[SQLFreeEnv](../libraries/odbc32/SQLFreeEnv.md)  
[SQLFreeHandle](../libraries/odbc32/SQLFreeHandle.md)  
[SQLGetDiagRec](../libraries/odbc32/SQLGetDiagRec.md)  
