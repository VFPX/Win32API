[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieveing general information about the driver and data source associated with an ODBC connection

## Code:
```foxpro  
DO decl

#DEFINE SQL_SUCCESS                   0
#DEFINE SQL_SUCCESS_WITH_INFO         1
#DEFINE SQL_HANDLE_DBC                2

#DEFINE SQL_DRIVER_NAME               6
#DEFINE SQL_DRIVER_ODBC_VER           77
#DEFINE SQL_DRIVER_VER                7
#DEFINE SQL_DM_VER                    171
#DEFINE SQL_DATA_SOURCE_NAME          2
#DEFINE SQL_SERVER_NAME               13
#DEFINE SQL_DATABASE_NAME             16
#DEFINE SQL_DBMS_NAME                 17
#DEFINE SQL_DBMS_VER                  18
#DEFINE SQL_USER_NAME                 47
#DEFINE SQL_CREATE_TABLE              132
#DEFINE SQL_PROCEDURES                21
#DEFINE SQL_UNION                     96
#DEFINE SQL_MAX_COLUMNS_IN_TABLE      101
#DEFINE SQL_MAX_TABLE_NAME_LEN        35
#DEFINE SQL_IDENTIFIER_QUOTE_CHAR     29
#DEFINE SQL_KEYWORDS                  89
#DEFINE SQL_SPECIAL_CHARACTERS        94

PRIVATE hEnv, hConn
STORE 0 TO hEnv, hConn

* parameters: DSN, user, password

*IF Not GetConnect("myxls", "", "")
IF Not GetConnect("Visual FoxPro Database", "", "")
*IF Not GetConnect("ECDCMusic", "", "")
*IF Not GetConnect("mssql", "sa", "")
	RETURN
ENDIF

CREATE CURSOR csResult (infotype C(30), datatype C(1),;
	infovalue C(254), largevalue M)

= AddInfo ("Data source name",        SQL_DATA_SOURCE_NAME,      "C")
= AddInfo ("Driver name",             SQL_DRIVER_NAME,           "C")
= AddInfo ("Driver version",          SQL_DRIVER_VER,            "C")
= AddInfo ("ODBC version",            SQL_DRIVER_ODBC_VER,       "C")
= AddInfo ("Driver manager version",  SQL_DM_VER,                "C")
= AddInfo ("Server name",             SQL_SERVER_NAME,           "C")
= AddInfo ("Database name",           SQL_DATABASE_NAME,         "C")
= AddInfo ("DBMS name",               SQL_DBMS_NAME,             "C")
= AddInfo ("DBMS version",            SQL_DBMS_VER,              "C")
= AddInfo ("User name",               SQL_USER_NAME,             "C")
= AddInfo ("CREATE TABLE support",    SQL_CREATE_TABLE,          "I")
= AddInfo ("SQL procedures support",  SQL_PROCEDURES,            "C")
= AddInfo ("UNION support",           SQL_UNION,                 "I")
= AddInfo ("Max table name",          SQL_MAX_TABLE_NAME_LEN,    "I")
= AddInfo ("Max cols in table",       SQL_MAX_COLUMNS_IN_TABLE,  "I")
= AddInfo ("Identifier quoting char", SQL_IDENTIFIER_QUOTE_CHAR, "C")
= AddInfo ("Keywords",                SQL_KEYWORDS,              "M")
= AddInfo ("Special characters",      SQL_SPECIAL_CHARACTERS,    "C")

DO GetDisconnect
GO TOP
BROW NORMAL NOWAIT
* end of main

FUNCTION AddInfo (lcInfoType, lnInfoType, lcDataType)
	LOCAL lcResult

	DO CASE
	CASE lcDataType = "C"
		lcResult = GetInfoStr(lnInfoType)
		INSERT INTO csResult (infotype, datatype, infovalue);
			VALUES (lcInfoType, lcDataType, lcResult)

	CASE lcDataType = "M"
		lcResult = GetInfoStr(lnInfoType)
		INSERT INTO csResult (infotype, datatype, infovalue, largevalue);
			VALUES (lcInfoType, lcDataType, "See memo field", lcResult)

	CASE lcDataType = "I"
		lcResult = GetInfoInt(lnInfoType, @lcDataType)
		INSERT INTO csResult (infotype, datatype, infovalue);
			VALUES (lcInfoType, lcDataType, lcResult)
	ENDCASE
RETURN

FUNCTION GetInfoInt (lnInfoType, lcDataType)
* returns a numeric parameter
	DECLARE SHORT SQLGetInfo IN odbc32;
		INTEGER ConnectionHandle, INTEGER InfoType,;
		INTEGER @InfoValuePtr, INTEGER BufLen, INTEGER @StrLenPtr

	LOCAL lnResult, lnBufLen
	STORE 0 TO lnResult, lnBufLen
	= SQLGetInfo (hConn, lnInfoType, @lnResult, 4, @lnBufLen)

	DO CASE
	CASE lnBuflen = 0
		RETURN "#error#"
	CASE lnBuflen = 2
		lcDataType = "S"
		RETURN LTRIM(STR(BitAnd(65535, lnResult)))
	CASE lnBuflen = 4
		lcDataType = "I"
		RETURN LTRIM(STR(lnResult))
	OTHER
		lcDataType = LTRIM(STR(lnBuflen))
		RETURN "#unknown type#"
	ENDCASE

FUNCTION GetInfoStr (lnInfoType)
* returns a string parameter
	DECLARE SHORT SQLGetInfo IN odbc32;
		INTEGER ConnectionHandle, INTEGER InfoType,;
		STRING @InfoValuePtr, INTEGER BufLen, INTEGER @StrLenPtr

	LOCAL lcBuffer, lnBufLen
	lcBuffer = REPLI(Chr(0), 4096)
	lnBufLen = 0
	= SQLGetInfo (hConn, lnInfoType, @lcBuffer, Len(lcBuffer), @lnBufLen)
RETURN Iif(lnBufLen>0, Left(lcBuffer, lnBufLen), "#error#")

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
		INTEGER ConnHandle, STRING ServerName, INTEGER NameLen1,;
		STRING UserName, INTEGER NameLen2, STRING Authentication,;
		INTEGER NameLen3

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
[SQLGetInfo](../libraries/odbc32/SQLGetInfo.md)  

## Comment:
A substantial number of various information requests is generally supported by any ODBC driver. Only a small part of them presented in the code above. Check a description for the SQLGetInfo on the MSDN online for the complete list of information requests.  
  
The most essential parameters of ODBC connection are certainly available through the native SQLGetProp() function in Visual FoxPro. This function appears to be both a wrapper and a filter for this API functionality.  
  
So if you need all available information of your connection the ODBC API is your choice.  
  
***  

