[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to obtain the number of rows affected by remote UPDATE, INSERT or DELETE statement

## Before you begin:
If **_TALLY** works perfectly for SQL statements executed on local tables, it can not be applied for statements performed against remote data sources.  

This code shows how to use SQLRowCount function, which is fully supported by Visual FoxPro ODBC Driver.  
  
***  


## Code:
```foxpro  
#DEFINE SQL_SUCCESS            0
#DEFINE SQL_SUCCESS_WITH_INFO  1
#DEFINE SQL_HANDLE_STMT        3
DO decl

LOCAL hFoxConn, hStmt, cStmt, nCount

hFoxConn = SQLConn("foxx")  && provide valid data source name
IF hFoxConn = -1
	? "Connection handle is invalid."
	RETURN
ENDIF

* obtaining real statement handle
hStmt = SQLGetProp(hFoxConn, "ODBChstmt")

* SQL statement to be executed -- provide valid statement
cStmt = "UPDATE products SET price=4.12 WHERE item LIKE "IK%""

IF SQLExecDirect(hStmt, cStmt, Len(cStmt)) = SQL_SUCCESS
	nCount=0
	IF SQLRowCount(hStmt, @nCount) = SQL_SUCCESS
		? "Records modified:", nCount
	ELSE
		? "SQLRowCount: ODBC error"
		= GetOdbcErr(hStmt, SQL_HANDLE_STMT)
	ENDIF
ELSE
	? "SQLExecDirect: ODBC error"
	= GetOdbcErr(hStmt, SQL_HANDLE_STMT)
ENDIF

= SQLDisc(hFoxConn)
* end of main

PROCEDURE GetOdbcErr(nHandle, nHandleType)
* printing diag records
	LOCAL nRecno, cSQLState, nNativeError, cMsg, nMsgLen, nResult

	nRecno = 1
	DO WHILE .T.
		cSQLState = SPACE(5)
		STORE 0 TO nNativeError, nMsgLen
		cMsg = SPACE(250)

		nResult = SQLGetDiagRec(nHandleType, nHandle, nRecno,;
			@cSQLState, @nNativeError, @cMsg, Len(cMsg), @nMsgLen)

		IF INLIST(nResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
			? "SQLSTATE=" + cSQLState +;
				", native error=" + LTRIM(STR(nNativeError)) +;
				", " + Left(cMsg, nMsgLen)
			nRecno = nRecno + 1
		ELSE
			EXIT
		ENDIF
	ENDDO

PROCEDURE decl
	DECLARE SHORT SQLGetDiagRec IN odbc32;
		INTEGER HandleType, INTEGER Handle, INTEGER RecNumber,;
		STRING @Sqlstate, INTEGER @NativeErrorPtr, STRING @MsgText,;
		INTEGER BufferLength, INTEGER @TextLengthPtr

	DECLARE SHORT SQLRowCount IN odbc32;
		INTEGER StatementHandle, INTEGER @RowCountPtr

	DECLARE SHORT SQLExecDirect IN odbc32;
		INTEGER StmtHandle, STRING StmtText, INTEGER TextLen  
```  
***  


## Listed functions:
[SQLExecDirect](../libraries/odbc32/SQLExecDirect.md)  
[SQLGetDiagRec](../libraries/odbc32/SQLGetDiagRec.md)  
[SQLRowCount](../libraries/odbc32/SQLRowCount.md)  

## Comment:
The SQLRowCount requires a connection handle as a parameter. Such handle can be obtained by calling FoxPro **SQLGetProp()** function like this: 
```foxpro
hStmt = SQLGetProp(hConn, "ODBChstmt")
```

where **hConn** is a connection handle returned by **SQLConnect()** function.  
  
I could not get a valid response from the SQLRowCount in combination with native SQLExec() function. All the way I got ODBC error **SQLSTATE=S1010** *(Function sequence error)*. I use VFP 6, so I may expect it works properly with a newer FoxPro version.  
  
After switching to ODBC API function SQLExecDirect the SQLRowCount immediately started to work, returning number of affected records for my UPDATE statements.  
  
***  

