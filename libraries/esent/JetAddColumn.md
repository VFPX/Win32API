[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetAddColumn
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Adds a new column to an existing table in an ESE database.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetAddColumn(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          JET_PCSTR szColumnName,
  __in          const JET_COLUMNDEF* pcolumndef,
  __in_opt      const void* pvDefault,
  __in          unsigned long cbDefault,
  __out_opt     JET_COLUMNID* pcolumnid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetAddColumn IN esent;
	INTEGER sesid,;
	INTEGER tableid,;
	STRING szColumnName,;
	STRING @pcolumndef,;
	STRING @pvDefault,;
	LONG cbDefault,;
	INTEGER @pcolumnid  
```  
***  


## Parameters:
sesid 
The database session context to use for the API call.

tableid 
The table to which to add the column.

szColumnName 
The name of the column to add.

pcolumndef 
A pointer to a JET_COLUMNDEF structure, which defines the data that can be stored in a column.

pvDefault 
A pointer to a buffer that contains the default value for the column.

cbDefault 
The size, in bytes, of the buffer that is specified in pvDefault.

pcolumnid 
A pointer to a JET_COLUMNID structure, which, on success, will receive the identifier of the newly created column.
  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  

