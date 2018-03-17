<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetDeleteTable
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
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
```txt  
sesid
The database session context to use for the API call.

dbid
The database identifier to use for the API call.

szTableName
The name of the table to delete.
  
```  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
See also: JetCloseTable   
  
***  

