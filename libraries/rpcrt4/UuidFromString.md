[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UuidFromString
Group: [Remote Procedure Call (RPC)](../../functions_group.md#Remote_Procedure_Call_(RPC))  -  Library: [rpcrt4](../../Libraries.md#rpcrt4)  
***  


#### Converts a string to a UUID.
***  


## Declaration:
```foxpro  
RPC_STATUS RPC_ENTRY UuidFromString(
	unsigned char __RPC_FAR *StringUuid,
	UUID __RPC_FAR *Uuid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UuidFromString IN Rpcrt4;
	STRING @StringUuid,;
	STRING @Uuid  
```  
***  


## Parameters:
StringUuid
Pointer to a string representation of a UUID.

Uuid
Returns a pointer to a UUID in binary form.  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
This function converts the string representation of a UUID, for example E911188C-E98C-478F-97E6-19F365143953, to the binary form.  
  
See also: [UuidToString](../rpcrt4/UuidToString.md), [UuidCreate](../rpcrt4/UuidCreate.md).  
  
***  

