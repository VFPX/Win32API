[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLDrivers
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLDrivers lists driver descriptions and driver attribute keywords.
***  


## Code examples:
[Enumerating ODBC drivers available on the local computer](../../samples/sample_285.md)  

## Declaration:
```foxpro  
SQLRETURN SQLDrivers(
	SQLHENV     EnvironmentHandle,
	SQLUSMALLINT     Direction,
	SQLCHAR *     DriverDescription,
	SQLSMALLINT     BufferLength1,
	SQLSMALLINT *     DescriptionLengthPtr,
	SQLCHAR *     DriverAttributes,
	SQLSMALLINT     BufferLength2,
	SQLSMALLINT *     AttributesLengthPtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLDrivers IN odbc32;
	INTEGER   EnvironmentHandle,;
	INTEGER   Direction,;
	STRING  @ DriverDescription,;
	INTEGER   BufferLength1,;
	INTEGER @ DescriptionLengthPtr,;
	STRING  @ DriverAttributes,;
	INTEGER   BufferLength2,;
	INTEGER @ AttributesLengthPtr
  
```  
***  


## Parameters:
EnvironmentHandle 
[Input]
Environment handle. 

Direction 
[Input]
Determines whether the Driver Manager fetches the next driver description in the list (SQL_FETCH_NEXT) or whether the search starts from the beginning of the list (SQL_FETCH_FIRST). 

DriverDescription 
[Output]
Pointer to a buffer in which to return the driver description. 

BufferLength1 
[Input]
Length of the *DriverDescription buffer, in bytes. 

DescriptionLengthPtr 
[Output]
Pointer to a buffer in which to return the total number of bytes (excluding the null-termination byte) available to return in *DriverDescription.

DriverAttributes 
[Output]
Pointer to a buffer in which to return the list of driver attribute value pairs (see "Comments"). 

BufferLength2 
[Input]
Length of the *DriverAttributes buffer, in bytes. 

AttributesLengthPtr 
[Output]
Pointer to a buffer in which to return the total number of bytes (excluding the null-termination byte) available to return in *DriverAttributes.  
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_NO_DATA, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  


## Comments:
SQLGetInstalledDrivers reads the [ODBC Drivers] section of the system information and returns a list of descriptions of the installed drivers.  
  
***  

