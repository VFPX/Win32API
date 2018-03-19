[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving current settings for an ODBC connection

## Code:
```foxpro  
DO decl

#DEFINE SQL_HANDLE_DBC           2
#DEFINE SQL_SUCCESS              0
#DEFINE SQL_SUCCESS_WITH_INFO    1

#DEFINE SQL_ATTR_ASYNC_ENABLE        4
#DEFINE SQL_ATTR_ACCESS_MODE         101
#DEFINE SQL_ATTR_AUTOCOMMIT          102
#DEFINE SQL_ATTR_LOGIN_TIMEOUT       103
#DEFINE SQL_ATTR_TRACE               104
#DEFINE SQL_ATTR_TRACEFILE           105
#DEFINE SQL_ATTR_TRANSLATE_DLL       106
#DEFINE SQL_TRANSLATE_OPTION         107
#DEFINE SQL_ATTR_TXN_ISOLATION       108
#DEFINE SQL_ATTR_CURRENT_CATALOG     109
#DEFINE SQL_ATTR_ODBC_CURSORS        110
#DEFINE SQL_ATTR_PACKET_SIZE         112
#DEFINE SQL_ATTR_CONNECTION_TIMEOUT  113
#DEFINE SQL_ATTR_METADATA_ID         10014

PRIVATE hVfpConn, hConn, hStat, gcErrMsg,;
	gcResult, gnResult, gcResultType

STORE 0 TO hVfpConn, hConn, hStat, gnResult
STORE "" TO gcResult, gcResultType, gcErrMsg

IF Not GetConnect("ECDCMusic", "","")
*IF Not GetConnect("FoxPro Files", "","")
*IF Not GetConnect("mssql", "sa","")
	= MessageB ("Unable to establish a connection")
	RETURN .F.
ENDIF

CREATE CURSOR csResult (attrname C(30), attrtype N(6), datatype C(1),;
	attrvalue C(250))

= GetAttr ("Async mode enabled", SQL_ATTR_ASYNC_ENABLE, "I")
= GetAttr ("Access mode", SQL_ATTR_ACCESS_MODE, "I")
= GetAttr ("Autocommit", SQL_ATTR_AUTOCOMMIT, "I")
= GetAttr ("Login timeout", SQL_ATTR_LOGIN_TIMEOUT, "I")
= GetAttr ("Trace", SQL_ATTR_TRACE, "C")
= GetAttr ("Trace file", SQL_ATTR_TRACEFILE, "C")
= GetAttr ("Translation DLL", SQL_ATTR_TRANSLATE_DLL, "I")
= GetAttr ("Translation Option", SQL_TRANSLATE_OPTION, "I")
= GetAttr ("Transaction isolation", SQL_ATTR_TXN_ISOLATION, "I")
= GetAttr ("Current catalog", SQL_ATTR_CURRENT_CATALOG, "C")
= GetAttr ("ODBC Cursor Library", SQL_ATTR_ODBC_CURSORS, "C")
= GetAttr ("Packet size", SQL_ATTR_PACKET_SIZE, "I")
= GetAttr ("Connection timeout", SQL_ATTR_CONNECTION_TIMEOUT, "I")
= GetAttr ("SQL_ATTR_METADATA_ID", SQL_ATTR_METADATA_ID, "I")

= SQLDisc(hVfpConn)

GO TOP
BROWSE NORMAL NOWAIT
* end of main

PROCEDURE GetAttr (lcAttrName, lnAttrType, lcResultType)
	DO CASE
	CASE lcResultType = "C"
		IF GetAttrStr (lnAttrType)
			INSERT INTO csResult (attrname, attrtype, datatype, attrvalue);
			VALUES (lcAttrName, lnAttrType, gcResultType, gcResult)
		ELSE
			INSERT INTO csResult (attrname, attrtype, datatype, attrvalue);
			VALUES (lcAttrName, lnAttrType, "*", gcErrMsg)
		ENDIF

	CASE lcResultType = "I"
		IF GetAttrNum (lnAttrType)
			INSERT INTO csResult (attrname, attrtype, datatype, attrvalue);
			VALUES (lcAttrName, lnAttrType, gcResultType, LTRIM(STR(gnResult)))
		ELSE
			INSERT INTO csResult (attrname, attrtype, datatype, attrvalue);
			VALUES (lcAttrName, lnAttrType, "*", gcErrMsg)
		ENDIF

	OTHER
		RETURN
	ENDCASE

FUNCTION GetAttrStr (lnAttrType)
	STORE "" TO gcErrMsg, gcResult, gcResultType

	DECLARE SHORT SQLGetConnectAttr IN odbc32;
		INTEGER ConnHandle, INTEGER Attribute, STRING @ValuePtr,;
		INTEGER BufferLength, INTEGER @StringLengthPtr

	LOCAL lcBuffer, lnBufsize, lnResult
	lcBuffer = Repli(Chr(0), 1024)
	lnBufsize = 0
	
	lnResult = SQLGetConnectAttr (hConn, lnAttrType,;
		@lcBuffer, Len(lcBuffer), @lnBufsize)

	IF Not INLIST(lnResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
		gcErrMsg = GetDiagRecs (hConn, SQl_HANDLE_DBC)
		RETURN .F.
	ELSE
		gcResultType = "C"
		gcResult = Left(lcBuffer, lnBufsize)
		RETURN .T.
	ENDIF

FUNCTION GetAttrNum (lnAttrType)
	STORE "" TO gcErrMsg, gnResult, gcResultType

	DECLARE SHORT SQLGetConnectAttr IN odbc32;
		INTEGER ConnHandle, INTEGER Attribute, INTEGER @ValuePtr,;
		INTEGER BufferLength, INTEGER @StringLengthPtr

	LOCAL lnBuffer, lnBufsize, lnResult
	STORE 0 TO lnBuffer, lnBufsize
	
	lnResult = SQLGetConnectAttr (hConn, lnAttrType,;
		@lnBuffer, 4, @lnBufsize)

	IF Not INLIST(lnResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
		gcErrMsg = GetDiagRecs (hConn, SQl_HANDLE_DBC)
		RETURN .F.
	ELSE
		DO CASE
		CASE lnBufsize = 2
			gcResultType = "S"
			gnResult = BitAnd(lnBuffer, 65535)
		CASE lnBufsize = 4
			gcResultType = "I"
			gnResult = lnBuffer
		OTHER
			gcResultType = "?"
			gnResult = lnBufsize
		ENDCASE
		RETURN .T.
	ENDIF

PROCEDURE GetDiagRecs (lnHandle, lnHandleType)
* printing diag records
	LOCAL lnRecno, lcSQLState, lnNativeError,;
		lcMessage, lnMsgLen, lnResult, lcResult

	lcResult = ""
	lnRecno = 1
	DO WHILE .T.
		lcSQLState = SPACE(5)
		STORE 0 TO lnNativeError, lnMsgLen
		lcMessage = SPACE(250)

		lnResult = SQLGetDiagRec (lnHandleType, lnHandle, lnRecno,;
			@lcSQLState, @lnNativeError,;
			@lcMessage, Len(lcMessage), @lnMsgLen)

		IF INLIST(lnResult, SQL_SUCCESS, SQL_SUCCESS_WITH_INFO)
			lcResult = lcResult +;
				Iif(EMPTY(lcResult), "", Chr(13)+Chr(10)) +;
				lcSQLState + "|" +;
				LTRIM(STR(lnNativeError)) + "|" +;
				Left(lcMessage, lnMsgLen)
			lnRecno = lnRecno + 1
		ELSE
			EXIT
		ENDIF
	ENDDO
RETURN lcResult

PROCEDURE GetConnect (lcDSN, lcUser, lcPwd)
	hVfpConn = SQLConnect(lcDSN, lcUser, lcPwd)
	IF hVfpConn > 0
		* ODBC connection handle
		hConn = SQlGetProp (hVfpConn, "ODBChdbc")

		* ODBC statement handle
		hStat = SQlGetProp (hVfpConn, "ODBChstmt")
		
		RETURN .T.
	ELSE
		RETURN .F.
	ENDIF

PROCEDURE decl
	DECLARE SHORT SQLGetDiagRec IN odbc32;
		INTEGER HandleType, INTEGER Handle, INTEGER RecNumber,;
		STRING @Sqlstate, INTEGER @NativeErrorPtr, STRING @MsgText,;
		INTEGER BufferLength, INTEGER @TextLengthPtr  
```  
***  


## Listed functions:
[SQLGetConnectAttr](../libraries/odbc32/SQLGetConnectAttr.md)  
[SQLGetDiagRec](../libraries/odbc32/SQLGetDiagRec.md)  
