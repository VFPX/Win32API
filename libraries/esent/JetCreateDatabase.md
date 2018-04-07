[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetCreateDatabase
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Creates and attaches a database file to be used with the ESE database engine.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetCreateDatabase(
  __in          JET_SESID sesid,
  __in          JET_PCSTR szFilename,
  __in_opt      JET_PCSTR szConnect,
  __out         JET_DBID* pdbid,
  __in          JET_GRBIT grbit
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetCreateDatabase IN esent;
	INTEGER sesid,;
	STRING szFilename,;
	INTEGER szConnect,;
	INTEGER @pdbid,;
	INTEGER grbit  
```  
***  


## Parameters:
sesid 
The database session context to use for the API call.

szFilename 
The name of the database to be created.

szConnect 
Reserved for future use. Set to NULL.

pdbid 
Pointer to a buffer that, on a successful call, contains the identifier of the database. On failure, the value is undefined.

grbit 
A group of bits specifying zero or more of predefined options.
  
***  


## Return value:
This function returns the JET_ERR datatype with one of predefined return codes.  
***  


## Comments:
Currently, up to seven databases can be created per instance. JetCreateDatabase will implicitly open the database. It is not necessarily to subsequently call JetOpenDatabase.  
  
See also: [JetAttachDatabase](..//JetAttachDatabase.md), [JetOpenDatabase](..//JetOpenDatabase.md), [JetCloseDatabase](../esent/JetCloseDatabase.md).  
  
***  

