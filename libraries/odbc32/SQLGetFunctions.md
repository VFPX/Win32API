[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLGetFunctions
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLGetFunctions returns information about whether a driver supports a specific ODBC function. 
***  


## Code examples:
[Testing an ODBC connection for supporting specific functionality](../../samples/sample_286.md)  

## Declaration:
```foxpro  
SQLRETURN SQLGetFunctions(
	SQLHDBC     ConnectionHandle,
	SQLUSMALLINT     FunctionId,
	SQLUSMALLINT *     SupportedPtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLGetFunctions IN odbc32;
	INTEGER   ConnectionHandle,;
	INTEGER   FunctionId,;
	INTEGER @ SupportedPtr
  
```  
***  


## Parameters:
ConnectionHandle 
[Input]
Connection handle. 

FunctionId 
[Input]
A #define value that identifies the ODBC function of interest.

SupportedPtr 
[Output] 
If FunctionId identifies a single ODBC function, SupportedPtr points to a single SQLUSMALLINT value that is SQL_TRUE if the specified function is supported by the driver, and SQL_FALSE if it is not supported.   
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

