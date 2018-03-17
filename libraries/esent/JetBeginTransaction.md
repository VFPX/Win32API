<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetBeginTransaction
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
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
```txt  
sesid
The session to use for this call.

  
```  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
This function can be called more than once on a single session to cause the creation of additional save points. These save points can be used to selectively keep or discard changes to the state of the database.  
  
See also: JetCommitTransaction, JetRollback   
  
***  

