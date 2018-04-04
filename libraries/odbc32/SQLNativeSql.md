[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLNativeSql
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../../libraries.md#odbc32)  
***  


#### SQLNativeSql returns the SQL string as modified by the driver. SQLNativeSql does not execute the SQL statement.
***  


## Code examples:
[Using vendor-neutral SQL constructs](../../samples/sample_287.md)  

## Declaration:
```foxpro  
SQLRETURN SQLNativeSql(
	SQLHDBC      ConnectionHandle,
	SQLCHAR *    InStatementText,
	SQLINTEGER   TextLength1,
	SQLCHAR *    OutStatementText,
	SQLINTEGER   BufferLength,
	SQLINTEGER * TextLength2Ptr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLNativeSql IN odbc32;
	INTEGER  ConnectionHandle,;
	STRING    InStatText,;
	INTEGER   TextLen1,;
	STRING  @ OutStatText,;
	INTEGER   BufferLen,;
	INTEGER @ TextLen2Ptr
  
```  
***  


## Parameters:
ConnectionHandle 
[Input]
Connection handle. 

InStatementText 
[Input]
SQL text string to be translated. 

TextLength1 
[Input]
Length of *InStatementText text string. 

OutStatementText 
[Output]
Pointer to a buffer in which to return the translated SQL string. 

BufferLength 
[Input]
Length of the *OutStatementText buffer. 

TextLength2Ptr 
[Output]
Pointer to a buffer in which to return the total number of bytes (excluding the null-termination byte) available to return in *OutStatementText.  
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  


## Comments:
Not all ODBC drivers support this function. As well not all of them support escape sequences. Both are supported by MS Access (MSDAO) and MS SQL Server. To my disappointment I found this functionality not supported by Visual FoxPro ODC driver (ver. 6.01.8629.01)  
  
SQLNativeSql returns the SQL string as modified by the driver. SQLNativeSql does not execute the SQL statement..  
  
Some links on vendor-neutral constructs:  
<a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/odbc/htm/odbcescape_sequences_in_odbc.asp">Escape Sequences in ODBC</a>  
<a href="http://www.devx.com/premier/mgznarch/vbpj/1997/06jun97/whgg.pdf">Step Up to Advanced SQL</a>  
<a href="http://www.webtechniques.com/archives/1997/07/north/">Using Interoperable SQL. By Ken North</a>  
  
***  

