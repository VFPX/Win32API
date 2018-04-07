[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UuidToString
Group: [Remote Procedure Call (RPC)](../../functions_group.md#Remote_Procedure_Call_(RPC))  -  Library: [rpcrt4](../../Libraries.md#rpcrt4)  
***  


#### Converts a UUID to a string.
***  


## Code examples:
[Generating random UUID values](../../samples/sample_024.md)  
[Generating sequential UUID values](../../samples/sample_587.md)  
[Generating UUID values from numbers](../../samples/sample_588.md)  

## Declaration:
```foxpro  
RPC_STATUS RPC_ENTRY UuidToString(
	UUID __RPC_FAR *Uuid ,
	unsigned char __RPC_FAR * __RPC_FAR *StringUuid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UuidToString IN Rpcrt4;
	STRING @Uuid,;
	LONG @StringUuid  
```  
***  


## Parameters:
Uuid
Pointer to a binary UUID.

StringUuid
Pointer to a pointer to the string into which the UUID specified in the Uuid parameter will be placed.  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
String representation of a UUID looks like this  
E911188C-E98C-478F-97E6-19F365143953  
  
The application is responsible for calling the RpcStringFree to release the memory that the system allocates for the <Em>StringUuid</Em>.  
  
Note that the <Em>StringUuid</Em> is a pointer to a pointer, which adds one or two subtleties to the RPC declarations and calls in VFP.  
  
See also: [UuidFromString](../rpcrt4/UuidFromString.md), [RtlMoveMemory](..//RtlMoveMemory.md).  
  
***  

