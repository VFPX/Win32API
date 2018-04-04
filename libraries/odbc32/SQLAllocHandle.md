[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLAllocHandle
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLAllocHandle allocates an environment, connection, statement, or descriptor handle.
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
SQLRETURN SQLAllocHandle(
     SQLSMALLINT     HandleType,
     SQLHANDLE     InputHandle,
     SQLHANDLE *     OutputHandlePtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLAllocHandle IN odbc32;
	INTEGER   HandleType,;
	INTEGER   InputHandle,;
	INTEGER @ OutputHandlePtr  
```  
***  


## Parameters:
HandleType 
[Input]
The type of handle to be allocated by SQLAllocHandle (predefined value).

InputHandle 
[Input]
The input handle in whose context the new handle is to be allocated.

OutputHandlePtr 
[Output]
Pointer to a buffer in which to return the handle to the newly allocated data structure. 
  
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO, SQL_INVALID_HANDLE, or SQL_ERROR.  
***  

