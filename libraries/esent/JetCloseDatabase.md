[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetCloseDatabase
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
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
sesid 
The database session context that will be used for the API call.

dbid 
The database to be closed. 

grbit 
Reserved for future use.  
***  


## Return value:
This function returns the JET_ERR data type with one of predefined return codes.  
***  


## Comments:
See also: [JetCreateDatabase](../esent/JetCreateDatabase.md), [JetOpenDatabase](..//JetOpenDatabase.md).  
  
***  

