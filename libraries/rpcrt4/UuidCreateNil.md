
## Function name : UuidCreateNil
Group: Remote Procedure Call (RPC) - Library: rpcrt4    
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
  
See also: UuidCreate, UuidCreateSequential   
  
***  

