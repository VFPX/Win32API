[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLConnect
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLConnect establishes connections to a driver and a data source. 
***  


## Code examples:
[Testing an ODBC connection for supporting specific functionality](../../samples/sample_286.md)  
[Using vendor-neutral SQL constructs](../../samples/sample_287.md)  
[Retrieveing general information about the driver and data source associated with an ODBC connection](../../samples/sample_289.md)  
[Establishing connection using the SQLDriverConnect](../../samples/sample_290.md)  
[Obtaining list of tables stored in an ODBC Data Source](../../samples/sample_409.md)  

## Declaration:
```foxpro  
SQLRETURN SQLConnect(
	SQLHDBC     ConnectionHandle,
	SQLCHAR *   ServerName,
	SQLSMALLINT NameLength1,
	SQLCHAR *   UserName,
	SQLSMALLINT NameLength2,
	SQLCHAR *   Authentication,
	SQLSMALLINT NameLength3);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLConnect IN odbc32 AS SQLConnect32;
	INTEGER ConnectionHandle,;
	STRING  ServerName,;
	INTEGER NameLength1,;
	STRING  UserName,;
	INTEGER NameLength2,;
	STRING  Authentication,;
	INTEGER NameLength3
  
```  
***  


## Parameters:
ConnectionHandle 
[Input]
Connection handle. 

ServerName 
[Input]
Data source name.

NameLength1 
[Input]
Length of *ServerName. 

UserName 
[Input]
User identifier. 

NameLength2 
[Input]
Length of *UserName. 

Authentication 
[Input]
Authentication string (typically the password). 

NameLength3 
[Input]
Length of *Authentication.   
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  


## Comments:
SQLAllocHandle with a HandleType of SQL_HANDLE_DBC is called to allocate a connection.  
  
When the application calls SQLDisconnect to disconnect, the connection is returned to the connection pool and is available for reuse.  
  
I guess I should not explain why this function is declared with an alias.  
  
***  

