[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetUpdate
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Performs an update operation including inserting a new row into a table or updating an existing row.

***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetUpdate(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __out_opt     void* pvBookmark,
  __in          unsigned long cbBookmark,
  __out_opt     unsigned long* pcbActual
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetUpdate IN esent;
	INTEGER sesid,;
	INTEGER tableid,;
	INTEGER @pvBookmark,;
	LONG cbBookmark,;
	LONG @pcbActual  
```  
***  


## Parameters:
sesid 
The session to use for this call.

tableid 
The cursor to use for this call.

pvBookmark 
Pointer to a returned bookmark for an inserted row.

cbBookmark 
Size of the buffer pointed to by pvBookmark.

pcbActual 
The returned size of the bookmark for the inserted row returned in pvBookmark.  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
The function is the final step in performing an insert or an update. The update is begun by calling JetPrepareUpdate and then by calling JetSetColumn or JetSetColumns one or more times to set the record state.   
  
Finally, JetUpdate is called to complete the update operation. Indexes are updated only by JetUpdate or JetUpdate2, and not during JetSetColumn or JetSetColumns.  
  
***  

