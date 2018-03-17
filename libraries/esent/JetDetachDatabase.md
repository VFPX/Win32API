<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetDetachDatabase
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
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
```txt  
sesid
The database session context to use for the API call.

szFilename
The name of the database to detach. If szFilename is NULL or an empty string, all databases attached to sesid will be detached.  
```  
***  


## Return value:
Returns the JET_ERR datatype with one of predefined return codes.  
***  


## Comments:
See also: JetCreateDatabase, JetAttachDatabase, JetCloseDatabase   
  
***  

