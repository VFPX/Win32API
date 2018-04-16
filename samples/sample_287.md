[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using vendor-neutral SQL constructs

## Before you begin:
The vendor-neutral constructs also known as "escape clauses" or "escape sequences" are useful for avoiding proprietary SQL syntax.  
  
***  


## Code:
```foxpro  
DO decl

#DEFINE SQL_HANDLE_DBC         2
#DEFINE SQL_SUCCESS            0
#DEFINE SQL_SUCCESS_WITH_INFO  1

PRIVATE hEnv, hConn
STORE 0 TO hEnv, hConn

* parameters being passed to initiate a connection: DSN, user, password
* replace them with connection parameters valid for your computer

*IF Not GetConnect("sqlserver", "sa", "")
*IF Not GetConnect("mysql", "sa", "")
IF Not GetConnect("ECDCMusic", "sa", "")
	RETURN
ENDIF

* samples of SQL commands with _Escape_ Sequences (escape clauses)
LOCAL lcSQL
lcSQL = [SELECT * FROM Titles WHERE pubdate < {d "1997-04-27"}]
*lcSQL = [SELECT {fn CONCAT({fn CONCAT(au_lname, ", ")}, au_fname)} FROM Authors]
*lcSQL = [SELECT {fn UCASE(Name)} FROM Customers]

* returns the SQL string as modified by the driver
* Notice: does not execute the SQL statement
? GetNativeSQL(lcSQL)

DO GetDisconnect
* end of main

FUNCTION GetNativeSQL (lcSQL)
	LOCAL lcBuffer, lnBufSize, lnResult
	lnBufSize = 4096
	lcBuffer = Repli(Chr(0), lnBufSize)

	lnResult = SQLNativeSql (hConn, lcSQL, Len(lcSQL),;
		@lcBuffer, lnBufSize, @lnBufSize)
	IF INLIST(lnResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
		RETURN Left(lcBuffer, lnBufSize)
	ELSE
		RETURN "#error#"
	ENDIF

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

PROCEDURE decl
	DECLARE SHORT SQLAllocEnv IN odbc32 INTEGER @env
	DECLARE SHORT SQLFreeEnv IN odbc32 INTEGER env

	DECLARE SHORT SQLFreeHandle IN odbc32;
		INTEGER HandleType, INTEGER Handle

	DECLARE SHORT SQLAllocHandle IN odbc32;
		INTEGER HandleType, INTEGER InputHandle,;
		INTEGER @OutputHandlePtr

	DECLARE SHORT SQLConnect IN odbc32 AS SQLConnect32;
		INTEGER ConnectionHandle,;
		STRING ServerName, INTEGER NameLength1,;
		STRING UserName, INTEGER NameLength2,;
		STRING Authentication, INTEGER NameLength3

	DECLARE SHORT SQLDisconnect IN odbc32 AS SQLDisconnect32;
		INTEGER ConnectionHandle

	DECLARE SHORT SQLNativeSql IN odbc32;
		INTEGER ConnectionHandle, STRING InStatText, INTEGER TextLen1,;
		STRING @OutStatText, INTEGER BufferLen, INTEGER @TextLen2Ptr  
```  
***  


## Listed functions:
[SQLAllocEnv](../libraries/odbc32/SQLAllocEnv.md)  
[SQLAllocHandle](../libraries/odbc32/SQLAllocHandle.md)  
[SQLConnect](../libraries/odbc32/SQLConnect.md)  
[SQLDisconnect](../libraries/odbc32/SQLDisconnect.md)  
[SQLFreeEnv](../libraries/odbc32/SQLFreeEnv.md)  
[SQLFreeHandle](../libraries/odbc32/SQLFreeHandle.md)  
[SQLNativeSql](../libraries/odbc32/SQLNativeSql.md)  

## Comment:
SQLNativeSql returns the SQL string as modified by the driver. SQLNativeSql does not execute the SQL statement..  
  
Some links on vendor-neutral constructs:  

[Escape Sequences in ODBC](https://docs.microsoft.com/en-us/sql/odbc/reference/appendixes/odbc-escape-sequences)  
[Using Interoperable SQL. By Ken North](https://people.apache.org/~jim/NewArchitect/webtech/1997/07/north/index.html)  
  
***  

