[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLDataSources
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLDataSources returns information about a data source. This function is implemented solely by the Driver Manager.
***  


## Code examples:
[Enumerating ODBC Data Sources available on the local computer](../../samples/sample_284.md)  

## Declaration:
```foxpro  
SQLRETURN SQLDataSources(
     SQLHENV     EnvironmentHandle,
     SQLUSMALLINT     Direction,
     SQLCHAR *     ServerName,
     SQLSMALLINT     BufferLength1,
     SQLSMALLINT *     NameLength1Ptr,
     SQLCHAR *     Description,
     SQLSMALLINT     BufferLength2,
     SQLSMALLINT *     NameLength2Ptr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLDataSources IN odbc32;
	INTEGER   EnvironmentHandle,;
	INTEGER   Direction,;
	STRING  @ ServerName,;
	INTEGER   BufferLength1,;
	INTEGER @ NameLength1Ptr,;
	STRING  @ Description,;
	INTEGER   BufferLength2,;
	INTEGER @ NameLength2Ptr  
```  
***  


## Parameters:
EnvironmentHandle 
[Input]
Environment handle. 

Direction 
[Input]
Determines which data source the Driver Manager returns information on.

ServerName 
[Output]
Pointer to a buffer in which to return the data source name. 

BufferLength1 
[Input]
Length of the *ServerName buffer, in bytes.

NameLength1Ptr 
[Output]
Pointer to a buffer in which to return the total number of bytes (excluding the null-termination byte) available to return in *ServerName. 

Description 
[Output]
Pointer to a buffer in which to return the description of the driver associated with the data source.

BufferLength2 
[Input]
Length of the *Description buffer. 

NameLength2Ptr 
[Output]
Pointer to a buffer in which to return the total number of bytes (excluding the null-termination byte) available to return in *Description.   
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_NO_DATA, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

