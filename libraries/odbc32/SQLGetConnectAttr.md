[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLGetConnectAttr
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLGetConnectAttr returns the current setting of a connection attribute.
***  


## Code examples:
[Retrieving current settings for an ODBC connection](../../samples/sample_292.md)  

## Declaration:
```foxpro  
SQLRETURN SQLGetConnectAttr(
	SQLHDBC      ConnectionHandle,
	SQLINTEGER   Attribute,
	SQLPOINTER   ValuePtr,
	SQLINTEGER   BufferLength,
	SQLINTEGER * StringLengthPtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLGetConnectAttr IN odbc32;
	INTEGER   ConnHandle,;
	INTEGER   Attribute,;
	INTEGER @ ValuePtr,;
	INTEGER   BufferLength,;
	INTEGER @ StringLengthPtr  
```  
***  


## Parameters:
ConnectionHandle 
[Input]
Connection handle. 

Attribute 
[Input]
Attribute to retrieve. 

ValuePtr 
[Output]
A pointer to memory in which to return the current value of the attribute specified by Attribute. 

BufferLength 
[Input]
If Attribute is an ODBC-defined attribute and ValuePtr points to a character string or a binary buffer, this argument should be the length of *ValuePtr. 

StringLengthPtr 
[Output]
A pointer to a buffer in which to return the total number of bytes available to return in *ValuePtr.   
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_NO_DATA, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

