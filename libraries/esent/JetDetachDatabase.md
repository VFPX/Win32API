[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetDetachDatabase
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Releases a database file that was previously attached to a database session.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetDetachDatabase(
  __in          JET_SESID sesid,
  __in          const tchar* szFilename
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetDetachDatabase IN esent;
	INTEGER sesid,;
	STRING szFilename  
```  
***  


## Parameters:
sesid 
The database session context to use for the API call.

szFilename 
The name of the database to detach. If szFilename is NULL or an empty string, all databases attached to sesid will be detached.  
***  


## Return value:
Returns the JET_ERR datatype with one of predefined return codes.  
***  


## Comments:
See also: [JetCreateDatabase](../esent/JetCreateDatabase.md), [JetAttachDatabase](..//JetAttachDatabase.md), [JetCloseDatabase](../esent/JetCloseDatabase.md).  
  
***  

