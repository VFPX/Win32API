[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLFreeEnv
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### In ODBC 3.x, the ODBC 2.0 function SQLFreeEnv has been replaced by SQLFreeHandle.
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
SQLRETURN SQLFreeEnv(
    SQLHANDLE  Handle);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLFreeEnv IN odbc32;
	INTEGER env  
```  
***  


## Parameters:
Handle 
[Input] 
The handle to be freed.   
***  


## Return value:
SQL_SUCCESS (0), SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

