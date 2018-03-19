[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# The SQLGetProp() creates a bridge between Visual FoxPro and the ODBC API

## Before you begin:
A native VFP functions ***SQLGetProp()*** returns a valid connection handle that can be used with appropriate ODBC API functions whenever they require a connection handle as a parameter.  

*hConn = SQLGetProp (myconn, "ODBChdbc")*  

Practically it means that you have all ODBC API functionality available for data connections established in Visual FoxPro through the native ***SQLConnect()*** function.  
  
***  


## Code:
```foxpro  
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

PRIVATE hVfpConn, hConn

* establishing an ODBC connection using regular VFP way
hVfpConn = SQLConnect("ECDCMusic")
IF hVfpConn <= 0
	= MessageB ("Unable to establish an ODBC connection.")
	RETURN
ENDIF

* retrieving internal ODBC connection handle
* that is valid to access ODBC API functions
hConn = SQLGetProp (hVfpConn, "ODBChdbc")

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

= SQLDisconnect(hVfpConn)

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
```  
***  


## Listed functions:
[SQLGetInfo](../libraries/odbc32/SQLGetInfo.md)  

## Comment:
The application connects to an ODBC data source using regular SQLConnect(). Then the connection handle is retrieved with the SQlGetProp() function. And this connection handle is the real one created behind the scene by Visual FoxPro itself with the SQLAllocHandle.  
  
Notice that the SQLGetProp() also provides a valid statement handle.  
  
Definitely the bridge is not too far.  
  
***  

