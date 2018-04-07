[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetDeleteTable
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Deletes a table in an ESE database.

***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetDeleteTable(
  __in          JET_SESID sesid,
  __in          JET_DBID dbid,
  __in          const tchar* szTableName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetDeleteTable IN esent;
	INTEGER sesid,;
	INTEGER dbid,;
	STRING szTableName  
```  
***  


## Parameters:
sesid 
The database session context to use for the API call.

dbid 
The database identifier to use for the API call.

szTableName 
The name of the table to delete.
  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
See also: [JetCloseTable](../esent/JetCloseTable.md).  
  
***  

