[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetBeginTransaction
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Causes a session to enter a transaction and create a new save point.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetBeginTransaction(
  __in          JET_SESID sesid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetBeginTransaction IN esent;
	INTEGER sesid  
```  
***  


## Parameters:
sesid 
The session to use for this call.

  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
This function can be called more than once on a single session to cause the creation of additional save points. These save points can be used to selectively keep or discard changes to the state of the database.  
  
See also: [JetCommitTransaction](../esent/JetCommitTransaction.md), [JetRollback](../esent/JetRollback.md).  
  
***  

