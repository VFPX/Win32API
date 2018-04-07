[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UuidCreate
Group: [Remote Procedure Call (RPC)](../../functions_group.md#Remote_Procedure_Call_(RPC))  -  Library: [rpcrt4](../../Libraries.md#rpcrt4)  
***  


#### Creates a new UUID.
***  


## Code examples:
[Generating random UUID values](../../samples/sample_024.md)  

## Declaration:
```foxpro  
RPC_STATUS RPC_ENTRY UuidCreate(
	UUID __RPC_FAR *Uuid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UuidCreate IN Rpcrt4;
	STRING @Uuid  
```  
***  


## Parameters:
Uuid
Returns a pointer to the created UUID.  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
For security reasons, UuidCreate was modified so that it no longer uses a machine"s MAC address to generate UUIDs.   
  
UuidCreateSequential was introduced to allow creation of UUIDs using the MAC address of a machine"s Ethernet card.  
  
Read article <a href="http://betterexplained.com/articles/the-quick-guide-to-guids/">GUIDs and UUIDs explained</a> on the BetterExplained.  
  
See also: [UuidCreateSequential](../rpcrt4/UuidCreateSequential.md), [UuidCreateNil](../rpcrt4/UuidCreateNil.md), [CoCreateGuid](../ole32/CoCreateGuid.md).  
  
***  

