[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLExecDirect
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
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
StatementHandle 
[Input]
Statement handle. 

StatementText 
[Input]
SQL statement to be executed. 

TextLength 
[Input]
Length of *StatementText.  
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO (1), or an error code: SQL_NEED_DATA, SQL_STILL_EXECUTING, SQL_ERROR, SQL_NO_DATA, SQL_INVALID_HANDLE.  
***  

