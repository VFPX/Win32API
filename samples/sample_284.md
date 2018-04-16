[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating ODBC Data Sources available on the local computer

## Short description:
The code shows how to use SQLDataSources function to retrieve lists of available Data Sources (either System or User DSNs).  
***  


## Before you begin:
The code shows how to use SQLDataSources function to retrieve lists of available Data Sources (either System or User DSNs).  

You may be interested in similar example:  
* [How to retrieve list of system DSNs (Data Source Name) with parameters](sample_375.md)  

  
***  


## Code:
```foxpro  
#DEFINE SQL_HANDLE_ENV   1
#DEFINE SQL_NULL_HANDLE  0
#DEFINE SQL_SUCCESS      0
#DEFINE SQL_SUCCESS_WITH_INFO 1
#DEFINE SQL_ERROR  -1
#DEFINE SQL_INVALID_HANDLE -2
#DEFINE SQL_NO_DATA 100
#DEFINE SQL_MAX_DSN_LENGTH 32
#DEFINE SQL_FETCH_NEXT  1
#DEFINE SQL_FETCH_FIRST 2
#DEFINE SQL_FETCH_FIRST_USER 31
#DEFINE SQL_FETCH_FIRST_SYSTEM 32
#DEFINE SQL_ATTR_ODBC_VERSION  200
#DEFINE SQL_OV_ODBC2 2
#DEFINE SQL_OV_ODBC3 3
DO decl

* defines which set of DSNs to retrieve
#DEFINE cnDirection SQL_FETCH_FIRST_SYSTEM

LOCAL hEnv

* there are two ways of creating a handle to ODBC environment
hEnv = GetEnvHandle1()
IF hEnv <> 0
	? "ODBC Version:", GetOdbcVersion(hEnv)
	= ListDSN(hEnv)
	= FreeEnvHandle1(hEnv)
ENDIF

*!*	hEnv = GetEnvHandle2()
*!*	IF hEnv <> 0
*!*		? "ODBC Version:", GetOdbcVersion(hEnv)
*!*		= ListDSN(hEnv)
*!*		= FreeEnvHandle2(hEnv)
*!*	ENDIF

SELECT csDsn
GO TOP
BROWSE NORMAL NOWAIT
* end of main

FUNCTION GetEnvHandle1
* allocates an environment (deprecated function)
	* an ODBC version is set by default during the allocation
	LOCAL hEnv
	hEnv = 0
	= SQLAllocEnv(@hEnv)
RETURN m.hEnv

PROCEDURE FreeEnvHandle1(hEnv)
	= SQLFreeEnv(hEnv)

PROCEDURE GetEnvHandle2
* allocates a handle to ODBC environment
* you have to set the ODBC version directly
* otherwise the following enumeration very likely will not work
	hEnv = 0
	= SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, @hEnv)
	= SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, SQL_OV_ODBC3, 0)
RETURN m.hEnv

PROCEDURE FreeEnvHandle2(hEnv)
	= SQLFreeHandle(SQL_HANDLE_ENV, hEnv)

FUNCTION GetOdbcVersion(hEnv)
* returns ODBC version for the given environment
	LOCAL AttrValue, lnRetLength
	STORE 0 TO AttrValue, lnRetLength
	= SQLGetEnvAttr(m.hEnv, SQL_ATTR_ODBC_VERSION,;
		@AttrValue, 0, @lnRetLength)
RETURN AttrValue

PROCEDURE ListDSN(hEnv)
#DEFINE STRING_BUFFER_SIZE 1024
	CREATE CURSOR csDSN (server C(SQL_MAX_DSN_LENGTH), descript C(100))

	LOCAL lnResult, lcServer, lcDescript,;
		lnServerLen, lnDescriptLen

	STORE 0 TO lnServerLen, lnDescriptLen
	STORE Repli(Chr(0), STRING_BUFFER_SIZE) TO lcServer, lcDescript

	lnResult = SQLDataSources(m.hEnv, cnDirection,;
		@lcServer, STRING_BUFFER_SIZE, @lnServerLen,;
		@lcDescript, STRING_BUFFER_SIZE, @lnDescriptLen)

	DO WHILE .T.
		IF INLIST(lnResult, SQL_ERROR, SQL_NO_DATA, SQL_INVALID_HANDLE)
			EXIT
		ELSE
			lcServer = SUBSTR(lcServer, 1, AT(Chr(0),lcServer)-1)
			lcDescript = SUBSTR(lcDescript, 1, AT(Chr(0),lcDescript)-1)
			INSERT INTO csDSN VALUES (lcServer, lcDescript)
		ENDIF

		STORE 0 TO lnServerLen, lnDescriptLen
		STORE Repli(Chr(0), STRING_BUFFER_SIZE) TO lcServer, lcDescript

		lnResult = SQLDataSources(m.hEnv, SQL_FETCH_NEXT,;
			@lcServer, STRING_BUFFER_SIZE, @lnServerLen,;
			@lcDescript, STRING_BUFFER_SIZE, @lnDescriptLen)
	ENDDO
RETURN

PROCEDURE decl
	DECLARE SHORT SQLAllocEnv IN odbc32 INTEGER @env
	DECLARE SHORT SQLFreeEnv IN odbc32 INTEGER env

	DECLARE SHORT SQLFreeHandle IN odbc32;
		INTEGER HandleType, INTEGER Handle

	DECLARE SHORT SQLAllocHandle IN odbc32;
		INTEGER HandleType, INTEGER InpHandle, INTEGER @OutpHandlePtr

	DECLARE SHORT SQLSetEnvAttr IN odbc32;
		INTEGER EnvHandle, INTEGER envattr,;
		INTEGER ValuePtr, INTEGER strlen

	DECLARE SHORT SQLDataSources IN odbc32;
		INTEGER EnvironmentHandle, INTEGER Direction,;
		STRING @ServerName, INTEGER BufferLength1,;
		INTEGER @NameLength1Ptr, STRING @Description,;
		INTEGER BufferLength2, INTEGER @NameLength2Ptr

	DECLARE SHORT SQLGetEnvAttr IN odbc32;
		INTEGER EnvironmentHandle, INTEGER Attribute,;
		INTEGER @ValuePtr, INTEGER BufferLength,;
		INTEGER @StringLengthPtr  
```  
***  


## Listed functions:
[SQLAllocEnv](../libraries/odbc32/SQLAllocEnv.md)  
[SQLAllocHandle](../libraries/odbc32/SQLAllocHandle.md)  
[SQLDataSources](../libraries/odbc32/SQLDataSources.md)  
[SQLFreeEnv](../libraries/odbc32/SQLFreeEnv.md)  
[SQLFreeHandle](../libraries/odbc32/SQLFreeHandle.md)  
[SQLGetEnvAttr](../libraries/odbc32/SQLGetEnvAttr.md)  
[SQLSetEnvAttr](../libraries/odbc32/SQLSetEnvAttr.md)  

## Comment:
Variable *mDirection* defines whether System, User or both DSNs will be retrieved depending on value assigned:  
* SQL_FETCH_FIRST_SYSTEM  
* SQL_FETCH_FIRST_USER  
* SQL_FETCH_FIRST  
  
***  

