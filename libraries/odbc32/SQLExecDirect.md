<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SQLExecDirect
Group: ODBC API - Library: odbc32    
***  


#### SQLExecDirect executes a preparable statement, using the current values of the parameter marker variables if any parameters exist in the statement.
***  


## Code examples:
[How to obtain the number of rows affected by remote UPDATE, INSERT or DELETE statement](../../samples/sample_416.md)  

## Declaration:
```foxpro  
SQLRETURN SQLExecDirect(
	SQLHSTMT   StatementHandle,
	SQLCHAR *  StatementText,
	SQLINTEGER TextLength);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLExecDirect IN odbc32;
	INTEGER StmtHandle,;
	STRING  StmtText,;
	INTEGER TextLen
  
```  
***  


## Parameters:
```txt  
StatementHandle
[Input]
Statement handle.

StatementText
[Input]
SQL statement to be executed.

TextLength
[Input]
Length of *StatementText.  
```  
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO (1), or an error code: SQL_NEED_DATA, SQL_STILL_EXECUTING, SQL_ERROR, SQL_NO_DATA, SQL_INVALID_HANDLE.  
***  

