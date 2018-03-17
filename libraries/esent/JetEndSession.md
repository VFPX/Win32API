<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetEndSession
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
***  


#### Ends the session, and cleans up and deallocates any resources associated with the specified session.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetEndSession(
  __in          JET_SESID sesid,
  __in          JET_GRBIT grbit
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetEndSession IN esent;
	INTEGER sesid,;
	INTEGER grbit  
```  
***  


## Parameters:
```txt  
sesid
The session to end. Associated resources are released when the session ends.

grbit
Reserved.
  
```  
***  


## Return value:
This function returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
This API will rollback any open transactions (not committed to level 0). Also all cursors associated with this session, and any sort tables that have been created or opened will be cleaned up.  
  
See also: JetBeginSession   
  
***  

