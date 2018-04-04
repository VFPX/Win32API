[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLGetInfo
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLGetInfo returns general information about the driver and data source associated with a connection.
***  


## Code examples:
[Retrieveing general information about the driver and data source associated with an ODBC connection](../../samples/sample_289.md)  
[The SQLGetProp() creates a bridge between Visual FoxPro and the ODBC API](../../samples/sample_291.md)  

## Declaration:
```foxpro  
SQLRETURN SQLGetInfo(
	SQLHDBC       ConnectionHandle,
	SQLUSMALLINT  InfoType,
	SQLPOINTER    InfoValuePtr,
	SQLSMALLINT   BufferLength,
	SQLSMALLINT * StringLengthPtr);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SQLGetInfo IN odbc32;
	INTEGER   ConnectionHandle,;
	INTEGER   InfoType,;
	STRING  @ InfoValuePtr,;
	INTEGER   BufLen,;
	INTEGER @ StrLenPtr  
```  
***  


## Parameters:
ConnectionHandle 
[Input]
Connection handle. 

InfoType 
[Input]
Type of information. 

InfoValuePtr 
[Output]
Pointer to a buffer in which to return the information. 

BufferLength 
[Input]
Length of the *InfoValuePtr buffer. If the value in *InfoValuePtr is not a character string or if InfoValuePtr is a null pointer, the BufferLength argument is ignored. 

StringLengthPtr 
[Output]
Pointer to a buffer in which to return the total number of bytes available to return in *InfoValuePtr.   
***  


## Return value:
SQL_SUCCESS, SQL_SUCCESS_WITH_INFO, SQL_ERROR, or SQL_INVALID_HANDLE.  
***  


## Comments:
The native SQLGetProp function in Visual FoxPro delivers a small part of this functionality. Probably it acts more like a filtering wrapper. Or may be a wrapping filter :) hey, whatever you choose.  
  
***  

