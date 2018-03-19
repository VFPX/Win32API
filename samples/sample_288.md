[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using SQLBrowseConnect to connect to a data source through a number of iterative calls (SQL Server)

## Before you begin:
Actually this code presents just a first step. Hopefully I will add more lines to it soon.   
  
***  


## Code:
```foxpro  
DO declare

#DEFINE SQL_HANDLE_DBC 2
#DEFINE SQL_ATTR_ODBC_VERSION 200
#DEFINE SQL_OV_ODBC2 2
#DEFINE SQL_OV_ODBC3 3
#DEFINE SQL_NEED_DATA 99

PRIVATE hEnv, hConn
STORE 0 TO hEnv, hConn

* allocating environment and connection handle
= SQLAllocEnv(@hEnv)
= SQLAllocHandle(SQL_HANDLE_DBC, hEnv, @hConn)

LOCAL lcConnStringIn, lcConnStringOut, lnLengthOut
lcConnStringOut = Repli(Chr(0), 1024)
lnLengthOut = 0

lcConnStringIn = "Driver={SQL Server}"
*lcConnStringIn = "DSN=mssql"

? "Connected:", SQLBrowseConnect(hConn,;
	lcConnStringIn, Len(lcConnStringIn),;
	@lcConnStringOut, Len(lcConnStringOut),;
	@lnLengthOut)

IF lnLengthOut > 0
	lcConnStringOut = PADR(lcConnStringOut, lnLengthOut)
	STORE lcConnStringOut TO _cliptext
	? lcConnStringOut
ENDIF

= SQLFreeHandle(SQL_HANDLE_DBC, hConn)
= SQLFreeEnv(hEnv)
* end of main

PROCEDURE declare
	DECLARE SHORT SQLAllocEnv IN odbc32 INTEGER @env
	DECLARE SHORT SQLFreeEnv IN odbc32 INTEGER env

	DECLARE SHORT SQLFreeHandle IN odbc32;
		INTEGER HandleType, INTEGER Handle

	DECLARE SHORT SQLAllocHandle IN odbc32;
		INTEGER HandleType, INTEGER InputHandle,;
		INTEGER @OutputHandlePtr

	DECLARE SHORT SQLBrowseConnect IN odbc32;
		INTEGER ConnectionHandle, STRING InConnectionString,;
		INTEGER StringLen1, STRING @OutConnectionString,;
		INTEGER BufferLen, INTEGER @StringLen2Ptr  
```  
***  


## Listed functions:
[SQLAllocEnv](../libraries/odbc32/SQLAllocEnv.md)  
[SQLAllocHandle](../libraries/odbc32/SQLAllocHandle.md)  
[SQLBrowseConnect](../libraries/odbc32/SQLBrowseConnect.md)  
[SQLFreeEnv](../libraries/odbc32/SQLFreeEnv.md)  
[SQLFreeHandle](../libraries/odbc32/SQLFreeHandle.md)  

## Comment:
Not all ODBC drivers support this functionality: *SQL Server, Oracle*, you name more.   
Unsupported by ODBC drivers for *MS Access, Visual FoxPro, MySQL*.  
  
Typical return from this function:  
*<Font color=#0000a0>SERVER:Server={Server1,Server2,Server3};UID:Login ID=?;PWD:Password=?;*APP:AppName=?;*WSID:WorkStation ID=?</Font>*  
  
***  

