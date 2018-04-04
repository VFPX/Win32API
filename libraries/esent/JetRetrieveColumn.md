[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : JetRetrieveColumn
Group: [Extensible Storage Engine (ESE, Jet Blue)](../../functions_group.md#Extensible_Storage_Engine_(ESE,_Jet_Blue))  -  Library: [esent](../../Libraries.md#esent)  
***  


#### Retrieves a single column value from the current record.
***  


## Code examples:
[Extensible Storage Engine class library](../../samples/sample_532.md)  

## Declaration:
```foxpro  
JET_ERR JET_API JetRetrieveColumn(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          JET_COLUMNID columnid,
  __out_opt     void* pvData,
  __in          unsigned long cbData,
  __out_opt     unsigned long* pcbActual,
  __in          JET_GRBIT grbit,
  __in_out_opt  JET_RETINFO* pretinfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER JetRetrieveColumn IN esent;
	INTEGER sesid,;
	INTEGER tableid,;
	INTEGER columnid,;
	INTEGER pvData,;
	LONG cbData,;
	LONG @pcbActual,;
	INTEGER grbit,;
	INTEGER pretinfo  
```  
***  


## Parameters:
sesid 
The session to use for this call.

tableid 
The cursor to use for this call.

columnid 
The JET_COLUMNID of the column to retrieve.

pvData 
The output buffer that receives the column value.

cbData 
The maximum size, in bytes, of the output buffer.

pcbActual 
Receives the actual size, in bytes, of the column value.

grbit 
A group of bits that contain the options to be used for this call.

pretinfo 
If pretinfo is give as NULL then the function behaves as though an itagSequence of 1 and an ibLongValue of 0 (zero) were given.  
***  


## Return value:
Returns the JET_ERR datatype with a predefined return code.  
***  

