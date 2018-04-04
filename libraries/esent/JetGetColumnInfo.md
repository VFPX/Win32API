[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetGetColumnInfo
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Retrieves information about a column.

***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetGetColumnInfo(
  __in          JET_SESID sesid,
  __in          JET_DBID dbid,
  __in          const tchar* szTableName,
  __in          const tchar* szColumnName,
  __out         void* pvResult,
  __in          unsigned long cbMax,
  __in          unsigned long InfoLevel
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetGetColumnInfo IN esent;
	INTEGER sesid,;
	INTEGER dbid,;
	STRING szTableName,;
	STRING szColumnName,;
	STRING @pvResult,;
	LONG cbMax,;
	LONG InfoLevel  
```  
***  


## Parameters:
sesid 
The database session context to use for the API call.

dbid 
Identifies, along with szTableName, the table that contains the column from which the information is retrieved.

szTableName 
Identifies, along with dbid, the table that contains the column from which the information is retrieved.

szColumnName 
The name of the column that information is fetched for.

pvResult 
Pointer to a buffer that will receive the information. The type of the buffer is dependent on InfoLevel. The caller must be configured to align the buffer appropriately.

cbMax 
The size, in bytes, of the buffer that is passed in pvResult.

InfoLevel 
The type of information to retrieve for the column that is specified by szColumnName. 
  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code. 
  
***  


## Comments:
JET_ColInfo and JET_ColInfoByColid both retrieve the same information. pvResult is interpreted as a JET_COLUMNDEF, and the fields of the JET_COLUMNDEF structure are filled in appropriately.  
  
***  

