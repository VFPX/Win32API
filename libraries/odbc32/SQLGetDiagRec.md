[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLGetDiagRec
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLGetDiagRec returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information. 
***  


## Code examples:
[Establishing connection using the SQLDriverConnect](../../samples/sample_290.md)  
[Retrieving current settings for an ODBC connection](../../samples/sample_292.md)  
[How to obtain the number of rows affected by remote UPDATE, INSERT or DELETE statement](../../samples/sample_416.md)  

## Declaration:
```foxpro  
SQLRETURN SQLGetDiagRec(
	SQLSMALLINT   HandleType,
	SQLHANDLE     Handle,
	SQLSMALLINT   RecNumber,
	SQLCHAR *     Sqlstate,
	SQLINTEGER *  NativeErrorPtr,
	QLCHAR *      MessageText,
	SQLSMALLINT   BufferLength,
	SQLSMALLINT * TextLengthPtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLGetDiagRec IN odbc32;
	INTEGER   HandleType,;
	INTEGER   Handle,;
	INTEGER   RecNumber,;
	STRING  @ Sqlstate,;
	INTEGER @ NativeErrorPtr,;
	STRING  @ MsgText,;
	INTEGER   BufferLength,;
	INTEGER @ TextLengthPtr
  
```  
***  


## Parameters:
HandleType 
[Input]
A handle type identifier that describes the type of handle for which diagnostics are required.

Handle 
[Input]
A handle for the diagnostic data structure, of the type indicated by HandleType. 

RecNumber 
[Input]
Indicates the status record from which the application seeks information. Status records are numbered from 1. 

SQLState 
[Output]
Pointer to a buffer in which to return a five-character SQLSTATE code pertaining to the diagnostic record RecNumber.

NativeErrorPtr 
[Output]
Pointer to a buffer in which to return the native error code, specific to the data source. 

MessageText 
[Output]
Pointer to a buffer in which to return the diagnostic message text string. 

BufferLength 
[Input]
Length of the *MessageText buffer in characters. 

TextLengthPtr 
[Output]
Pointer to a buffer in which to return the total number of bytes available to return in *MessageText.   
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  

