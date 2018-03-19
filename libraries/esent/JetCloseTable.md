
## Function name : JetCloseTable
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
***  


#### Closes an open table in a database. The table is a temporary table or a normal table.

***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetCloseTable(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetCloseTable IN esent;
	INTEGER sesid,;
	INTEGER tableid  
```  
***  


## Parameters:
sesid 
Identifies the database session context that will be used for the API call.

tableid 
Identifies the table to be closed.
  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
See also: JetCreateTable, JetOpenTable   
  
***  

