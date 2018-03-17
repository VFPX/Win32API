<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetCloseDatabase
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
***  


#### Closes a database file that was previously opened with JetOpenDatabase.

***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetCloseDatabase(
  __in          JET_SESID sesid,
  __in          JET_DBID dbid,
  __in          JET_GRBIT grbit
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetCloseDatabase IN esent;
	INTEGER sesid,;
	INTEGER dbid,;
	INTEGER grbit  
```  
***  


## Parameters:
```txt  
sesid
The database session context that will be used for the API call.

dbid
The database to be closed.

grbit
Reserved for future use.  
```  
***  


## Return value:
This function returns the JET_ERR data type with one of predefined return codes.  
***  


## Comments:
See also: JetCreateDatabase, JetOpenDatabase   
  
***  

