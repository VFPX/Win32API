[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLTables
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### Returns the list of table, catalog, or schema names, and table types, stored in a specific data source. The driver returns the information as a result set.
***  


## Code examples:
[Obtaining list of tables stored in an ODBC Data Source](../../samples/sample_409.md)  

## Declaration:
```foxpro  
SQLRETURN SQLTables(
	SQLHSTMT    StatementHandle,
	SQLCHAR *   CatalogName,
	SQLSMALLINT NameLength1,
	SQLCHAR *   SchemaName,
	SQLSMALLINT NameLength2,
	SQLCHAR *   TableName,
	SQLSMALLINT NameLength3,
	SQLCHAR *   TableType,
	SQLSMALLINT NameLength4);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLTables IN odbc32 AS SQLTables32;
	INTEGER StatementHandle,;
	STRING  CatalogName,;
	SHORT   NameLen1,;
	STRING  SchemaName,;
	SHORT   NameLen2,;
	STRING  TableName,;
	SHORT   NameLen3,;
	STRING  TableType,;
	SHORT   NameLen4
  
```  
***  


## Parameters:
StatementHandle 
[Input]
Statement handle for retrieved results. 

CatalogName 
[Input]
Catalog name. 

NameLength1 
[Input]
Length in characters of *CatalogName. 

SchemaName 
[Input]
String search pattern for schema names. 

NameLength2 
[Input]
Length in characters of *SchemaName. 

TableName 
[Input]
String search pattern for table names. 

NameLength3 
[Input]
Length in characters of *TableName. 

TableType 
[Input]
List of table types to match.

NameLength4 
[Input]
Length in characters of *TableType.   
***  


## Return value:
SQL_SUCCESS (0), SQL_SUCCESS_WITH_INFO, SQL_STILL_EXECUTING, SQL_ERROR (-1), or SQL_INVALID_HANDLE.  
***  


## Comments:
FoxPro native SQLTables() function is practically an ideal wrapper for this API routine. So in most cases staying within FoxPro functionality is more convenient.  
  
***  

