[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UuidCompare
Group: [Remote Procedure Call (RPC)](../../functions_group.md#Remote_Procedure_Call_(RPC))  -  Library: [rpcrt4](../../Libraries.md#rpcrt4)  
***  


#### Compare two UUIDs and determine their order. The returned value gives the order.
***  


## Declaration:
```foxpro  
signed int RPC_ENTRY UuidCompare(
	UUID __RPC_FAR *Uuid1,
	UUID __RPC_FAR *Uuid2,
	RPC_STATUS __RPC_FAR *Status
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UuidCompare IN Rpcrt4;
	STRING Uuid1,;
	STRING Uuid2,;
	INTEGER @nStatus  
```  
***  


## Parameters:
Uuid1
Pointer to a UUID. This UUID is compared with the UUID specified in the Uuid2 parameter.

Uuid2
Pointer to a UUID. This UUID is compared with the UUID specified in the Uuid1 parameter.

Status
Returns any errors that may occur, and will typically be set by the function to RPC_S_OK upon return.  
***  


## Return value:
Returns -1 (1st is less), 0 (equal) or 1 (greater) based on the comparison of the 1st and 2nd UUIDS.  
***  


## Comments:
See also: [UuidCreate](../rpcrt4/UuidCreate.md), [UuidCreateSequential](../rpcrt4/UuidCreateSequential.md).  
  
***  

