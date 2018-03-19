[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining list of tables stored in an ODBC Data Source

## Before you begin:
Practically there is no need in SQLTables API call in FoxPro, because it is already encapsulated in VFP native SQLTables() function.   

This code sample allows you to see what is happening behind the scene, when a list of tables is requested. Also it shows how to use SQLBindCol and SQLFetch calls to process an SQL statement.  
  
***  


## Code:
```foxpro  
DO decl

#DEFINE SQL_SUCCESS            0
#DEFINE SQL_ERROR             -1
#DEFINE SQL_SUCCESS_WITH_INFO  1
#DEFINE SQL_HANDLE_DBC         2
#DEFINE SQL_HANDLE_STMT        3
#DEFINE SQL_CHAR               1

PRIVATE hEnv, hConn
STORE 0 TO hEnv, hConn
CREATE CURSOR csResult (tbl_name C(25), tbl_type C(25), tbl_cat C(128))

* provide valid data source name (DSN), user name, and password
IF GetConnect("TestDSN", "", "")
	DO GetTables
ENDIF

DO GetDisconnect

SELECT csResult
GO TOP
BROW NORMAL NOWAIT
* end of main

PROCEDURE GetTables
#DEFINE STR_LEN  254
	LOCAL hStmt, nResult, nIndex, cBuffer, nLen
	hStmt = 0
	* allocating statement handle for the connection
	= SQLAllocHandle(SQL_HANDLE_STMT, hConn, @hStmt)

	IF hStmt = 0
		? "Could not allocate statement handle."
		RETURN
	ENDIF
	
	* enumerating tables for the data source
	nResult = SQLTables32(hStmt, Null,0, Null,0, Null,0, Null,0)

	IF Not INLIST(nResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
		? "Error returned while requesting list of tables:", nResult
	ELSE
		* allocating memory blocks for data buffers and buffer lengths
		* I tried but SQLFetch did not work properly
		* with FoxPro variables used in this role
		DIMEN arrCols[5,3]
		FOR nIndex=1 TO 5
			arrCols[nIndex,1] = GlobalAlloc(0, STR_LEN)
			arrCols[nIndex,2] = GlobalAlloc(0, 4)
		ENDFOR

		= SQLBindCol(hStmt, 1, SQL_CHAR, arrCols[1,1],;
			STR_LEN, arrCols[1,2]) && table_cat
		= SQLBindCol(hStmt, 2, SQL_CHAR, arrCols[2,1],;
			STR_LEN, arrCols[2,2]) && table_schem
		= SQLBindCol(hStmt, 3, SQL_CHAR, arrCols[3,1],;
			STR_LEN, arrCols[3,2]) && table_name
		= SQLBindCol(hStmt, 4, SQL_CHAR, arrCols[4,1],;
			STR_LEN, arrCols[4,2]) && table_type
		= SQLBindCol(hStmt, 5, SQL_CHAR, arrCols[5,1],;
			STR_LEN, arrCols[5,2]) && remarks
		
		DO WHILE .T.
			nResult = SQLFetch(hStmt)
			IF Not INLIST(nResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
				EXIT
			ENDIF
			
			FOR nIndex=1 TO 5
				* obtaining effective length for the column data
				cBuffer = Repli(Chr(0), 4)
				= CopyMemory(@cBuffer, arrCols[nIndex,2], 4)
				nLen = buf2dword(cBuffer)

				IF BETW(nLen, 1, STR_LEN)
				* copying from the column data to string variable
					cBuffer = Repli(Chr(0), nLen)
					= CopyMemory(@cBuffer, arrCols[nIndex,1], nLen)
				ELSE
					cBuffer = ""
				ENDIF
				arrCols[nIndex,3] = cBuffer
			ENDFOR
			INSERT INTO csResult VALUES (;
				arrCols[3,3], arrCols[4,3], arrCols[1,3])
		ENDDO

		* releasing allocated memory
		FOR nIndex=1 TO 5
			= GlobalFree(arrCols[nIndex,2])
			= GlobalFree(arrCols[nIndex,1])
		ENDFOR
	ENDIF
	* releasing statement handle
	= SQLFreeHandle(SQL_HANDLE_STMT, hStmt)

FUNCTION GetConnect(lcServer, lcUser, lcPwd)
	= SQLAllocEnv(@hEnv)
	IF hEnv = 0
		? "Could not allocate ODBC environment."
		RETURN .F.
	ENDIF

	= SQLAllocHandle(SQL_HANDLE_DBC, hEnv, @hConn)
	IF hConn = 0
		? "Could not allocate ODBC connection handle."
		RETURN .F.
	ENDIF
	
	LOCAL lnResult
	lnResult = SQLConn32(hConn, lcServer, Len(lcServer),;
		lcUser, Len(lcUser), lcPwd, Len(lcPwd))

	IF INLIST(lnResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
		RETURN .T.
	ELSE
		? "Could not connect to the [" + lcServer + "]."
		RETURN .F.
	ENDIF

PROCEDURE GetDisconnect
	= SQLDisc32(hConn)
	= SQLFreeHandle(SQL_HANDLE_DBC, hConn)
	= SQLFreeEnv(hEnv)

PROCEDURE decl
	DECLARE SHORT SQLAllocEnv IN odbc32 INTEGER @env
	DECLARE SHORT SQLFreeEnv IN odbc32 INTEGER env
	DECLARE SHORT SQLFetch IN odbc32 INTEGER StatementHandle
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes
	DECLARE SHORT SQLFreeHandle IN odbc32 INTEGER HandleType, INTEGER Handle
	DECLARE SHORT SQLDisconnect IN odbc32 AS SQLDisc32 INTEGER ConnHandle

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Dst, INTEGER Src, INTEGER nLen

	DECLARE SHORT SQLAllocHandle IN odbc32;
		INTEGER HandleType, INTEGER InputHandle,;
		INTEGER @OutputHandlePtr

	DECLARE SHORT SQLConnect IN odbc32 AS SQLConn32;
		INTEGER ConnHandle, STRING SrvName, INTEGER NameLen1,;
		STRING UserName, INTEGER NameLen2,;
		STRING Authent, INTEGER NameLen3

	DECLARE SHORT SQLTables IN odbc32 AS SQLTables32;
		INTEGER StatementHandle, STRING CatalogName, SHORT NameLen1,;
		STRING SchemaName, SHORT NameLen2, STRING TableName,;
		SHORT NameLen3, STRING TableType, SHORT NameLen4

	DECLARE SHORT SQLBindCol IN odbc32;
		INTEGER StatementHandle, SHORT ColumnNumber, SHORT TargetType,;
		INTEGER TargetValuePtr, INTEGER BufferLen, INTEGER StrLen_or_Ind

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[SQLAllocEnv](../libraries/odbc32/SQLAllocEnv.md)  
[SQLAllocHandle](../libraries/odbc32/SQLAllocHandle.md)  
[SQLBindCol](../libraries/odbc32/SQLBindCol.md)  
[SQLConnect](../libraries/odbc32/SQLConnect.md)  
[SQLDisconnect](../libraries/odbc32/SQLDisconnect.md)  
[SQLFetch](../libraries/odbc32/SQLFetch.md)  
[SQLFreeEnv](../libraries/odbc32/SQLFreeEnv.md)  
[SQLFreeHandle](../libraries/odbc32/SQLFreeHandle.md)  
[SQLTables](../libraries/odbc32/SQLTables.md)  
