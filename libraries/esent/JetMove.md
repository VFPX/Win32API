<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : JetMove
Group: Extensible Storage Engine (ESE, Jet Blue) - Library: esent    
***  


#### Positions a cursor at the start or end of an index and traverses the entries in that index either forward or backward.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetMove(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          long cRow,
  __in          JET_GRBIT grbit
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetMove IN esent;
	INTEGER sesid,;
	INTEGER tableid,;
	LONG cRow,;
	INTEGER grbit  
```  
***  


## Parameters:
```txt  
sesid
The session to use for this call.

tableid
The cursor to use for this call.

cRow
An arbitrary offset that indicates the desired movement of the cursor on the current index.

grbit
A group of bits that specify zero or more of predefined options.

  
```  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
If this function succeeds, the cursor will be positioned at an index entry that matches the requested location or offset.   
  
If a record has been prepared for update, that update will be canceled. If an index range is in effect and JET_MoveFirst or JET_MoveLast was specified, that index range will be canceled. No change to the database state will occur.   
  
***  

