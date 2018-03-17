<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SQLFetch
Group: ODBC API - Library: odbc32    
***  


#### SQLFetch fetches the next rowset of data from the result set and returns data for all bound columns.
***  


## Code examples:
[Obtaining list of tables stored in an ODBC Data Source](../../samples/sample_409.md)  

## Declaration:
```foxpro  
SQLRETURN SQLFetch(
	SQLHSTMT StatementHandle);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLFetch IN odbc32;
	INTEGER StatementHandle  
```  
***  


## Parameters:
```txt  
StatementHandle
[Input]
Statement handle.  
```  
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO, SQL_NO_DATA, SQL_STILL_EXECUTING, SQL_ERROR (-1), or SQL_INVALID_HANDLE (-2).  
***  


## Comments:
SQLFetch returns the next rowset in the result set. It can be called only while a result set exists—that is, after a call that creates a result set and before the cursor over that result set is closed. If any columns are bound, it returns the data in those columns.  
  
When the result set is created, the cursor is positioned before the start of the result set. SQLFetch fetches the next rowset. It is equivalent to calling SQLFetchScroll with FetchOrientation set to SQL_FETCH_NEXT.  
  
***  

