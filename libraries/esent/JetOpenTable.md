[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetOpenTable
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Opens a cursor on an existing table.

***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetOpenTable(
  __in          JET_SESID sesid,
  __in          JET_DBID dbid,
  __in          const tchar* szTableName,
  __in_opt      const void* pvParameters,
  __in          unsigned long cbParameters,
  __in          JET_GRBIT grbit,
  __out         JET_TABLEID* ptableid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetOpenTable IN esent;
	INTEGER sesid,;
	INTEGER dbid,;
	STRING szTableName,;
	INTEGER pvParameters,;
	INTEGER cbParameters,;
	INTEGER grbit,;
	INTEGER @ptableid  
```  
***  


## Parameters:
sesid 
The database session context to use.

dbid 
The database identifier to use to find the table.

szTableName 
The name of the table to open.

pvParameters 
Deprecated. Set to NULL.

cbParameters 
Deprecated. Set to 0 (zero).

grbit 
A group of bits specifying zero or more of predefined options.

ptableid 
On success, points to the identifier of the table. On failure, the contents for ptableid are undefined.  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return codes  
***  

