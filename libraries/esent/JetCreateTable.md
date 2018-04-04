[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetCreateTable
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Creates an empty table in an ESE database.

***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetCreateTable(
  __in          JET_SESID sesid,
  __in          JET_DBID dbid,
  __in          const tchar* szTableName,
  __in          unsigned long lPages,
  __in          unsigned long lDensity,
  __out         JET_TABLEID* ptableid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetCreateTable IN esent;
	INTEGER sesid,;
	INTEGER dbid,;
	STRING szTableName,;
	LONG lPages,;
	LONG lDensity,;
	INTEGER @ptableid  
```  
***  


## Parameters:
sesid 
The database session context to use.

dbid 
The database identifier to use.

szTableName 
The name of the index to create.

lPages 
The initial number of database pages to allocate for the table.

lDensity 
The table density, in percentage points.

ptableid 
On success, the table identifier is returned in this field. The value is undefined if the API does not return JET_errSuccess (0).

  
***  


## Return value:
Returns the JET_ERR datatype with one of predefined return codes.  
***  


## Comments:
JetCreateTable creates a table which does not contain any columns. To add columns, see JetAddColumn.  
  
The table should usually be closed with JetCloseTable.  
  
  
  
***  

