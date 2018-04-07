[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UuidCreateNil
Group: [Remote Procedure Call (RPC)](../../functions_group.md#Remote_Procedure_Call_(RPC))  -  Library: [rpcrt4](../../Libraries.md#rpcrt4)  
***  


#### Creates a nil-valued UUID.
***  


## Declaration:
```foxpro  
RPC_ENTRY UuidCreateNil(
	UUID __RPC_FAR *Nil_Uuid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UuidCreateNil IN Rpcrt4;
	STRING @Uuid  
```  
***  


## Parameters:
Nil_Uuid
Returns a nil-valued UUID.  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
{00000000-0000-0000-0000-000000000000}  
  
See also: [UuidCreate](../rpcrt4/UuidCreate.md), [UuidCreateSequential](../rpcrt4/UuidCreateSequential.md).  
  
***  

