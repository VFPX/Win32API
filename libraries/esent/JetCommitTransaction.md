[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetCommitTransaction
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Commits the changes made to the state of the database during the current save point and migrates them to the previous save point.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetCommitTransaction(
  __in          JET_SESID sesid,
  __in          JET_GRBIT grbit
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetCommitTransaction IN esent;
	INTEGER sesid,;
	INTEGER grbit  
```  
***  


## Parameters:
sesid 
The session to use for this call.

grbit 
A group of bits specifying zero or more of predefined options.
  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
On success, any changes made to the database during the current save point for the given session will be committed and that save point will be ended. If the last save point for the session was ended then the transaction will optionally be flushed to the transaction log file and the session will exit the transaction.  
  
On failure, the transactional state of the session will remain unchanged. No change to the database state will occur. The application should call JetRollback to abort the transaction.  
  
See also: [JetBeginTransaction](../esent/JetBeginTransaction.md), [JetRollback](../esent/JetRollback.md).  
  
***  

