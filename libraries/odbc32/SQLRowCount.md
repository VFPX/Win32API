<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SQLRowCount
Group: ODBC API - Library: odbc32    
***  


#### SQLRowCount returns the number of rows affected by an UPDATE, INSERT, or DELETE statement.
***  


## Code examples:
[How to obtain the number of rows affected by remote UPDATE, INSERT or DELETE statement](../../samples/sample_416.md)  

## Declaration:
```foxpro  
SQLRETURN SQLRowCount(
	SQLHSTMT     StmtHandle,
	SQLINTEGER * RowCountPtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLRowCount IN odbc32;
	INTEGER   StmtHandle,;
	INTEGER @ RowCountPtr  
```  
***  


## Parameters:
```txt  
StatementHandle
[Input]
Statement handle.

RowCountPtr
[Output]
Points to a buffer in which to return a row count.  
```  
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO (1), or error codes: SQL_ERROR, SQL_INVALID_HANDLE  
***  


## Comments:
When SQLRowCount returns SQL_ERROR or SQL_SUCCESS_WITH_INFO, an associated SQLSTATE value can be obtained by calling SQLGetDiagRec with a HandleType of SQL_HANDLE_STMT and a Handle of StatementHandle.  
  
When SQLExecute, SQLExecDirect, SQLBulkOperations, SQLSetPos, or SQLMoreResults is called, the SQL_DIAG_ROW_COUNT field of the diagnostic data structure is set to the row count, and the row count is cached in an implementation-dependent way.  
  
***  

