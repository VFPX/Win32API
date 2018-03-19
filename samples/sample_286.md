[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Testing an ODBC connection for supporting specific functionality

## Code:
```foxpro  
DO decl

#DEFINE SQL_TRUE               1
#DEFINE SQL_FALSE              0
#DEFINE SQL_SUCCESS            0
#DEFINE SQL_SUCCESS_WITH_INFO  1
#DEFINE SQL_HANDLE_DBC         2

PRIVATE hEnv, hConn
STORE 0 TO hEnv, hConn

* parameters: DSN, user, password
IF Not GetConnect("ECDCMusic", "", "")
	RETURN
ENDIF

CREATE CURSOR csResult (sql_api C(30), support C(3))

= test("SQL_API_SQLALLOCCONNECT", 1)
= test("SQL_API_SQLALLOCENV", 2)
= test("SQL_API_SQLALLOCHANDLE", 1001)
= test("SQL_API_SQLALLOCHANDLESTD", 73)
= test("SQL_API_SQLALLOCSTMT", 3)
= test("SQL_API_SQLBINDCOL", 4)
= test("SQL_API_SQLBINDPARAM", 1002)
= test("SQL_API_SQLBINDPARAMETER", 72)
= test("SQL_API_SQLBROWSECONNECT", 55)
= test("SQL_API_SQLBULKOPERATIONS", 24)
= test("SQL_API_SQLCANCEL", 5)
= test("SQL_API_SQLCLOSECURSOR", 1003)
= test("SQL_API_SQLCOLATTRIBUTE", 6)
= test("SQL_API_SQLCOLATTRIBUTES", 6)
= test("SQL_API_SQLCOLUMNPRIVILEGES", 56)
= test("SQL_API_SQLCOLUMNS", 40)
= test("SQL_API_SQLCONNECT", 7)
= test("SQL_API_SQLCOPYDESC", 1004)
= test("SQL_API_SQLDATASOURCES", 57)
= test("SQL_API_SQLDESCRIBECOL", 8)
= test("SQL_API_SQLDESCRIBEPARAM", 58)
= test("SQL_API_SQLDISCONNECT", 9)
= test("SQL_API_SQLDRIVERCONNECT", 41)
= test("SQL_API_SQLDRIVERS", 71)
= test("SQL_API_SQLENDTRAN", 1005)
= test("SQL_API_SQLERROR", 10)
= test("SQL_API_SQLEXECDIRECT", 11)
= test("SQL_API_SQLEXECUTE", 12)
= test("SQL_API_SQLEXTENDEDFETCH", 59)
= test("SQL_API_SQLFETCH", 13)
= test("SQL_API_SQLFETCHSCROLL", 1021)
= test("SQL_API_SQLFOREIGNKEYS", 60)
= test("SQL_API_SQLFREECONNECT", 14)
= test("SQL_API_SQLFREEENV", 15)
= test("SQL_API_SQLFREEHANDLE", 1006)
= test("SQL_API_SQLFREESTMT", 16)
= test("SQL_API_SQLGETCONNECTATTR", 1007)
= test("SQL_API_SQLGETCONNECTOPTION", 42)
= test("SQL_API_SQLGETCURSORNAME", 17)
= test("SQL_API_SQLGETDATA", 43)
= test("SQL_API_SQLGETDESCFIELD", 1008)
= test("SQL_API_SQLGETDESCREC", 1009)
= test("SQL_API_SQLGETDIAGFIELD", 1010)
= test("SQL_API_SQLGETDIAGREC", 1011)
= test("SQL_API_SQLGETENVATTR", 1012)
= test("SQL_API_SQLGETFUNCTIONS", 44)
= test("SQL_API_SQLGETINFO", 45)
= test("SQL_API_SQLGETSTMTATTR", 1014)
= test("SQL_API_SQLGETSTMTOPTION", 46)
= test("SQL_API_SQLGETTYPEINFO", 47)
= test("SQL_API_SQLMORERESULTS", 61)
= test("SQL_API_SQLNATIVESQL", 62)
= test("SQL_API_SQLNUMPARAMS", 63)
= test("SQL_API_SQLNUMRESULTCOLS", 18)
= test("SQL_API_SQLPARAMDATA", 48)
= test("SQL_API_SQLPARAMOPTIONS", 64)
= test("SQL_API_SQLPREPARE", 19)
= test("SQL_API_SQLPRIMARYKEYS", 65)
= test("SQL_API_SQLPROCEDURECOLUMNS", 66)
= test("SQL_API_SQLPROCEDURES", 67)
= test("SQL_API_SQLPUTDATA", 49)
= test("SQL_API_SQLROWCOUNT", 20)
= test("SQL_API_SQLSETCONNECTATTR", 1016)
= test("SQL_API_SQLSETCONNECTOPTION", 50)
= test("SQL_API_SQLSETCURSORNAME", 21)
= test("SQL_API_SQLSETDESCFIELD", 1017)
= test("SQL_API_SQLSETDESCREC", 1018)
= test("SQL_API_SQLSETENVATTR", 1019)
= test("SQL_API_SQLSETPARAM", 22)
= test("SQL_API_SQLSETPOS", 68)
= test("SQL_API_SQLSETSCROLLOPTIONS", 69)
= test("SQL_API_SQLSETSTMTATTR", 1020)
= test("SQL_API_SQLSETSTMTOPTION", 51)
= test("SQL_API_SQLSPECIALCOLUMNS", 52)
= test("SQL_API_SQLSTATISTICS", 53)
= test("SQL_API_SQLTABLEPRIVILEGES", 70)
= test("SQL_API_SQLTABLES", 54)
= test("SQL_API_SQLTRANSACT", 23)

DO GetDisconnect

SELECT csResult
GO TOP
BROWSE NORMAL NOWAIT
* end of main

FUNCTION GetConnect (lcServer, lcUser, lcPwd)
	= SQLAllocEnv(@hEnv)
	IF hEnv = 0
		= MessageB ("Unable to allocate ODBC environment")
		RETURN .F.
	ENDIF

	= SQLAllocHandle (SQL_HANDLE_DBC, hEnv, @hConn)
	IF hConn = 0
		= MessageB ("Unable to allocate ODBC connection handle")
		RETURN .F.
	ENDIF
	
	LOCAL lnResult
	lnResult = SQLConnect32 (hConn, lcServer, Len(lcServer),;
		lcUser, Len(lcUser), lcPwd, Len(lcPwd))

	IF INLIST(lnResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
		RETURN .T.
	ELSE
		= MessageB ("Unable to connect to the [" + lcServer + "]")
		RETURN .F.
	ENDIF

PROCEDURE GetDisconnect
	IF hConn <> 0
		= SQLDisconnect32 (hConn)
		= SQLFreeHandle (SQL_HANDLE_DBC, hConn)
	ENDIF

	IF hEnv <> 0
		= SQLFreeEnv(hEnv)
	ENDIF
RETURN

FUNCTION test (lcApi, lnFunctionId)
	LOCAL lnResult, lnSupport

	lnSupport = SQL_FALSE
	lnResult = SQLGetFunctions (hConn, lnFunctionId, @lnSupport)

	IF INLIST(lnResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
		INSERT INTO csResult VALUES (lcApi, Iif(lnSupport=SQL_TRUE, "Yes"," - "))
	ELSE
		INSERT INTO csResult VALUES (lcApi, "Err")
	ENDIF

PROCEDURE decl
	DECLARE SHORT SQLAllocEnv IN odbc32 INTEGER @env
	DECLARE SHORT SQLFreeEnv IN odbc32 INTEGER env

	DECLARE SHORT SQLFreeHandle IN odbc32;
		INTEGER HandleType, INTEGER Handle

	DECLARE SHORT SQLAllocHandle IN odbc32;
		INTEGER HandleType, INTEGER InputHandle,;
		INTEGER @OutputHandlePtr

	DECLARE SHORT SQLGetFunctions IN odbc32;
		INTEGER ConnectionHandle, INTEGER FunctionId,;
		INTEGER @SupportedPtr

	DECLARE SHORT SQLConnect IN odbc32 AS SQLConnect32;
		INTEGER ConnectionHandle,;
		STRING ServerName, INTEGER NameLength1,;
		STRING UserName, INTEGER NameLength2,;
		STRING Authentication, INTEGER NameLength3

	DECLARE SHORT SQLDisconnect IN odbc32 AS SQLDisconnect32;
		INTEGER ConnectionHandle  
```  
***  


## Listed functions:
[SQLAllocEnv](../libraries/odbc32/SQLAllocEnv.md)  
[SQLAllocHandle](../libraries/odbc32/SQLAllocHandle.md)  
[SQLConnect](../libraries/odbc32/SQLConnect.md)  
[SQLDisconnect](../libraries/odbc32/SQLDisconnect.md)  
[SQLFreeEnv](../libraries/odbc32/SQLFreeEnv.md)  
[SQLFreeHandle](../libraries/odbc32/SQLFreeHandle.md)  
[SQLGetFunctions](../libraries/odbc32/SQLGetFunctions.md)  
