<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UuidCreateNil
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
```txt  
Nil_Uuid
Returns a nil-valued UUID.  
```  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
{00000000-0000-0000-0000-000000000000}  
  
See also: UuidCreate, UuidCreateSequential   
  
***  

