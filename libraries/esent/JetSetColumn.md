[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetSetColumn
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Modifies a single column value in a modified record to be inserted or to update the current record.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetSetColumn(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          JET_COLUMNID columnid,
  __in_opt      const void* pvData,
  __in          unsigned long cbData,
  __in          JET_GRBIT grbit,
  __in_opt      JET_SETINFO* psetinfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetSetColumn IN esent;
	INTEGER sesid,;
	INTEGER tableid,;
	INTEGER columnid,;
	INTEGER pvData,;
	LONG cbData,;
	INTEGER grbit,;
	INTEGER psetinfo  
```  
***  


## Parameters:
sesid 
The session to use for this call.

tableid 
The cursor to use for this call.

columnid 
The JET_COLUMNID of the column to be retrieved.

pvData 
Input buffer containing data to use for column value.

cbData 
Size in bytes of the input buffer.

grbit 
A group of bits that contain the options to be used for this call.

psetinfo 
Pointer to optional input parameters that can be set for this function using the JET_SETINFO structure.  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  


## Comments:
The function can overwrite an existing value, add a new value to a sequence of values in a multi-valued column, remove a value from a sequence of values in a multi-valued column, or update all or part of a long value, a column of type JET_coltypLongText or JET_coltypeLongBinary.   
  
See also: [JetPrepareUpdate](JetPrepareUpdate.md), [JetUpdate](../esent/JetUpdate.md).  
  
***  

