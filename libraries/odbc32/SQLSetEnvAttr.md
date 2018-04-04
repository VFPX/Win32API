[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLSetEnvAttr
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLSetEnvAttr sets attributes that govern aspects of environments.
***  


## Code examples:
[Enumerating ODBC Data Sources available on the local computer](../../samples/sample_284.md)  

## Declaration:
```foxpro  
SQLRETURN SQLSetEnvAttr(
	SQLHENV     EnvironmentHandle,
	SQLINTEGER  Attribute,
	SQLPOINTER  ValuePtr,
	SQLINTEGER  StringLength);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLSetEnvAttr IN odbc32;
	INTEGER EnvironmentHandle,;
	INTEGER Attribute,;
	INTEGER ValuePtr,;
	INTEGER StringLength  
```  
***  


## Parameters:
EnvironmentHandle 
[Input]
Environment handle. 

Attribute 
[Input]
Attribute to set, listed in "Comments." 

ValuePtr 
[Input]
Pointer to the value to be associated with Attribute.

StringLength 
[Input] If ValuePtr points to a character string or a binary buffer, this argument should be the length of *ValuePtr. If ValuePtr is an integer, StringLength is ignored.   
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

