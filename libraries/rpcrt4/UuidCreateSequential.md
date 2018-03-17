<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UuidCreateSequential
Group: Remote Procedure Call (RPC) - Library: rpcrt4    
***  


#### Creates a new UUID.
***  


## Code examples:
[Generating sequential UUID values](../../samples/sample_587.md)  

## Declaration:
```foxpro  
RPC_STATUS RPC_ENTRY UuidCreateSequential(
	UUID __RPC_FAR *Uuid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UuidCreateSequential IN Rpcrt4;
	STRING @Uuid  
```  
***  


## Parameters:
```txt  
Uuid
Returns a pointer to the created UUID.  
```  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
For security reasons, UuidCreate was modified so that it no longer uses a machine"s MAC address to generate UUIDs.   
  
UuidCreateSequential was introduced to allow creation of UUIDs using the MAC address of a machine"s Ethernet card.  
  
See also: UuidCreate, UuidCreateNil, UuidCompare, CoCreateGuid   
  
***  

