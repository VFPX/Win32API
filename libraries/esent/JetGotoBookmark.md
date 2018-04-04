[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetGotoBookmark
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Positions a cursor to an index entry for the record that is associated with the specified bookmark.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetGotoBookmark(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          void* pvBookmark,
  __in          unsigned long cbBookmark
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetGotoBookmark IN esent;
	INTEGER sesid,;
	INTEGER tableid,;
	INTEGER pvBookmark,;
	LONG cbBookmark  
```  
***  


## Parameters:
sesid 
The session to use for this call.

tableid 
The cursor to use for this call.

pvBookmark 
The buffer that contains the bookmark to use to position the cursor.

cbBookmark 
The size of the bookmark in the buffer (most likely 4 bytes).  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  

