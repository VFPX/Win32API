[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetRollback
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Undoes the changes made to the state of the database and returns to the last save point.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetRollback(
  __in          JET_SESID sesid,
  __in          JET_GRBIT grbit
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetRollback IN esent;
	INTEGER sesid,;
	INTEGER grbit  
```  
***  


## Parameters:
sesid 
The session to use for this call.

grbit 
A group of bits that contain the options to be used for this call.
  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
On success, any changes made to the database during the current save point for the given session will be undone and that save point will be ended. If the last save point for the session was ended then the session will exit the transaction.  
  
On failure, the transactional state of the session will remain unchanged. No change to the database state will occur. A failure during rollback is considered to be a catastrophic database error.  
  
See also: [JetBeginTransaction](../esent/JetBeginTransaction.md), [JetCommitTransaction](../esent/JetCommitTransaction.md).  
  
***  

