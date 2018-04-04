[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLDisconnect
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLDisconnect closes the connection associated with a specific connection handle.
***  


## Code examples:
[Testing an ODBC connection for supporting specific functionality](../../samples/sample_286.md)  
[Using vendor-neutral SQL constructs](../../samples/sample_287.md)  
[Retrieveing general information about the driver and data source associated with an ODBC connection](../../samples/sample_289.md)  
[Establishing connection using the SQLDriverConnect](../../samples/sample_290.md)  
[Obtaining list of tables stored in an ODBC Data Source](../../samples/sample_409.md)  

## Declaration:
```foxpro  
SQLRETURN SQLDisconnect(
	SQLHDBC ConnectionHandle);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLDisconnect IN odbc32;
AS SQLDisconnect32;
		INTEGER ConnectionHandle  
```  
***  


## Parameters:
ConnectionHandle 
[Input]
Connection handle. 
  
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  


## Comments:
I guess I should not explain why this function is declared with an alias.  
  
***  

