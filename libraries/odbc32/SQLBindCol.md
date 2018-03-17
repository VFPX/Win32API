<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SQLBindCol
Group: ODBC API - Library: odbc32    
***  


#### SQLBindCol binds application data buffers to columns in the result set.
***  


## Code examples:
[Obtaining list of tables stored in an ODBC Data Source](../../samples/sample_409.md)  

## Declaration:
```foxpro  
SQLRETURN SQLBindCol(
	SQLHSTMT     StatementHandle,
	SQLUSMALLINT ColumnNumber,
	SQLSMALLINT  TargetType,
	SQLPOINTER   TargetValuePtr,
	SQLINTEGER   BufferLength,
	SQLLEN *     StrLen_or_Ind);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLBindCol IN odbc32;
	INTEGER StatementHandle,;
	SHORT   ColumnNumber,;
	SHORT   TargetType,;
	INTEGER TargetValuePtr,;
	INTEGER BufferLen,;
	INTEGER StrLen_or_Ind
  
```  
***  


## Parameters:
```txt  
StatementHandle
[Input]
Statement handle.

ColumnNumber
[Input]
Number of the result set column to bind.

TargetType
[Input]
The identifier of the C data type of the *TargetValuePtr buffer.

TargetValuePtr
[Deferred Input/Output]
Pointer to the data buffer to bind to the column. SQLFetch and SQLFetchScroll return data in this buffer.

BufferLength
[Input]
Length of the *TargetValuePtr buffer in bytes.

StrLen_or_IndPtr
[Deferred Input/Output]
Pointer to the length/indicator buffer to bind to the column. SQLFetch and SQLFetchScroll return a value in this buffer.  
```  
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO, SQL_ERROR (-1), or SQL_INVALID_HANDLE (-2).  
***  

