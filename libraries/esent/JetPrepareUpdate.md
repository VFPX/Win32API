[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetPrepareUpdate
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### This is the first operation in performing an update, for the purposes of inserting a new record or replacing an existing record with new values.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetPrepareUpdate(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          unsigned long prep
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetPrepareUpdate IN esent;
	INTEGER sesid,;
	INTEGER tableid,;
	LONG prep  
```  
***  


## Parameters:
sesid 
The session to use for this call.

tableid 
The cursor to use for this call.

prep 
The options that can be used to prepare for an update
  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.   
***  


## Comments:
 Updates are done by calling JetPrepareUpdate, then calling JetSetColumn or JetSetColumns zero or more times and finally by calling JetUpdate to complete the operation.  
  
***  

