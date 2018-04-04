[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLBrowseConnect
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLBrowseConnect supports an iterative method of discovering and enumerating the attributes and attribute values required to connect to a data source. Each call to SQLBrowseConnect returns successive levels of attributes and attribute values.
***  


## Code examples:
[Using SQLBrowseConnect to connect to a data source through a number of iterative calls (SQL Server)](../../samples/sample_288.md)  

## Declaration:
```foxpro  
SQLRETURN SQLBrowseConnect(
	SQLHDBC       ConnectionHandle,
	SQLCHAR *     InConnectionString,
	SQLSMALLINT   StringLength1,
	SQLCHAR *     OutConnectionString,
	SQLSMALLINT   BufferLength,
	SQLSMALLINT * StringLength2Ptr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLBrowseConnect IN odbc32;
	INTEGER   ConnectionHandle,;
	STRING    InConnectionString,;
	INTEGER   StringLength1,;
	STRING  @ OutConnectionString,;
	INTEGER   BufferLength,;
	INTEGER @ StringLength2Ptr  
```  
***  


## Parameters:
ConnectionHandle 
[Input]
Connection handle. 

InConnectionString 
[Input]
Browse request connection string (see "InConnectionString Argument" in "Comments"). 

StringLength1 
[Input]
Length of *InConnectionString. 

OutConnectionString 
[Output]
Pointer to a buffer in which to return the browse result connection string. 

BufferLength 
[Input]
Length of the *OutConnectionString buffer. 

StringLength2Ptr 
[Output]
The total number of bytes available to return in *OutConnectionString.   
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_NEED_DATA, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  


## Comments:
SQLBrowseConnect requires an allocated connection. The driver may establish a connection with the data source during the browsing process.  
  
On each call to SQLBrowseConnect, the application specifies the connection attribute values in the browse request connection string. The driver returns successive levels of attributes and attribute values in the browse result connection string; it returns SQL_NEED_DATA (99) as long as there are connection attributes that have not yet been enumerated in the browse request connection string.   
  
***  

