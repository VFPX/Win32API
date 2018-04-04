[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLFreeHandle
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLFreeHandle frees resources associated with a specific environment, connection, statement, or descriptor handle.
***  


## Code examples:
[Enumerating ODBC Data Sources available on the local computer](../../samples/sample_284.md)  
[Testing an ODBC connection for supporting specific functionality](../../samples/sample_286.md)  
[Using vendor-neutral SQL constructs](../../samples/sample_287.md)  
[Using SQLBrowseConnect to connect to a data source through a number of iterative calls (SQL Server)](../../samples/sample_288.md)  
[Retrieveing general information about the driver and data source associated with an ODBC connection](../../samples/sample_289.md)  
[Establishing connection using the SQLDriverConnect](../../samples/sample_290.md)  
[Obtaining list of tables stored in an ODBC Data Source](../../samples/sample_409.md)  

## Declaration:
```foxpro  
SQLRETURN SQLFreeHandle(
	SQLSMALLINT HandleType,
	SQLHANDLE   Handle);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLFreeHandle IN odbc32;
	INTEGER HandleType,;
	INTEGER Handle  
```  
***  


## Parameters:
HandleType 
[Input]
The type of handle to be freed by SQLFreeHandle.

Handle 
[Input]
The handle to be freed.   
***  


## Return value:
SQL_SUCCESS (0), SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

