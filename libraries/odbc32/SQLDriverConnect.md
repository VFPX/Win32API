[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLDriverConnect
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLDriverConnect is an alternative to SQLConnect. It supports data sources that require more connection information than the three arguments in SQLConnect, dialog boxes to prompt the user for all connection information, and data sources that are not defined in the system information.
***  


## Code examples:
[Establishing connection using the SQLDriverConnect](../../samples/sample_290.md)  

## Declaration:
```foxpro  
SQLRETURN SQLDriverConnect(
	SQLHDBC       ConnectionHandle,
	SQLHWND       WindowHandle,
	SQLCHAR *     InConnectionString,
	SQLSMALLINT   StringLength1,
	SQLCHAR *     OutConnectionString,
	SQLSMALLINT   BufferLength,
	SQLSMALLINT * StringLength2Ptr,
	SQLUSMALLINT  DriverCompletion);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLDriverConnect IN odbc32;
	INTEGER   ConnHandle,;
	INTEGER   WinHandle,;
	STRING    InConnStr,;
	SHORT     StrLen1,;
	STRING  @ OutConnStr,;
	SHORT     BufLen,;
	SHORT   @ StrLen2Ptr,;
	INTEGER   DriverCompletion
  
```  
***  


## Parameters:
ConnectionHandle 
[Input]
Connection handle. 

WindowHandle 
[Input]
Window handle. The application can pass the handle of the parent window, if applicable, or a null pointer if either the window handle is not applicable or SQLDriverConnect will not present any dialog boxes. 

InConnectionString 
[Input]
A full connection string (see the syntax in "Comments"), a partial connection string, or an empty string. 

StringLength1 
[Input]
Length of *InConnectionString, in bytes. 

OutConnectionString 
[Output]
Pointer to a buffer for the completed connection string. 

BufferLength 
[Input]
Length of the *OutConnectionString buffer. 

StringLength2Ptr 
[Output]
Pointer to a buffer in which to return the total number of characters available to return in *OutConnectionString. 

DriverCompletion 
[Input]
Flag that indicates whether the Driver Manager or driver must prompt for more connection information.  
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_NO_DATA, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

