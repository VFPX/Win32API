[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLAllocEnv
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### In ODBC 3.x, the ODBC 2.x function SQLAllocEnv has been replaced by SQLAllocHandle.
***  


## Code examples:
[Enumerating ODBC Data Sources available on the local computer](../../samples/sample_284.md)  
[Enumerating ODBC drivers available on the local computer](../../samples/sample_285.md)  
[Testing an ODBC connection for supporting specific functionality](../../samples/sample_286.md)  
[Using vendor-neutral SQL constructs](../../samples/sample_287.md)  
[Using SQLBrowseConnect to connect to a data source through a number of iterative calls (SQL Server)](../../samples/sample_288.md)  
[Retrieveing general information about the driver and data source associated with an ODBC connection](../../samples/sample_289.md)  
[Establishing connection using the SQLDriverConnect](../../samples/sample_290.md)  
[Obtaining list of tables stored in an ODBC Data Source](../../samples/sample_409.md)  

## Declaration:
```foxpro  
SQLRETURN SQLAllocEnv(
	SQLHANDLE * OutputHandlePtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLAllocEnv IN odbc32;
	INTEGER @ env  
```  
***  


## Parameters:
OutputHandlePtr 
[Output] 
Pointer to a buffer in which to return the handle to the newly allocated data structure.   
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO, SQL_INVALID_HANDLE, or SQL_ERROR.  
***  

