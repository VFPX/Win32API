[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLGetEnvAttr
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLGetEnvAttr returns the current setting of an environment attribute.
***  


## Code examples:
[Enumerating ODBC Data Sources available on the local computer](../../samples/sample_284.md)  

## Declaration:
```foxpro  
SQLRETURN SQLGetEnvAttr(
     SQLHENV     EnvironmentHandle,
     SQLINTEGER     Attribute,
     SQLPOINTER     ValuePtr,
     SQLINTEGER     BufferLength,
     SQLINTEGER *   StringLengthPtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLGetEnvAttr IN odbc32;
	INTEGER   EnvironmentHandle,;
	INTEGER   Attribute,;
	INTEGER @ ValuePtr,;
	INTEGER   BufferLength,;
	INTEGER @ StringLengthPtr
  
```  
***  


## Parameters:
EnvironmentHandle 
[Input]

Environment handle. 
Attribute 
[Input]

Attribute to retrieve. 
ValuePtr 
[Output]
Pointer to a buffer in which to return the current value of the attribute specified by Attribute. 
BufferLength 
[Input]
If ValuePtr points to a character string, this argument should be the length of *ValuePtr. If *ValuePtr is an integer, BufferLength is ignored. 

StringLengthPtr 
[Output]
A pointer to a buffer in which to return the total number of bytes (excluding the null-termination character) available to return in *ValuePtr. 
  
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_NO_DATA, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

