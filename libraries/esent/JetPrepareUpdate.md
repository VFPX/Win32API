<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetPrepareUpdate
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
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
```txt  
sesid
The session to use for this call.

tableid
The cursor to use for this call.

prep
The options that can be used to prepare for an update
  
```  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.   
***  


## Comments:
 Updates are done by calling JetPrepareUpdate, then calling JetSetColumn or JetSetColumns zero or more times and finally by calling JetUpdate to complete the operation.  
  
***  

