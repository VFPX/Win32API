<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UuidFromString
Group: Remote Procedure Call (RPC) - Library: rpcrt4    
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
```txt  
StringUuid
Pointer to a string representation of a UUID.

Uuid
Returns a pointer to a UUID in binary form.  
```  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
This function converts the string representation of a UUID, for example E911188C-E98C-478F-97E6-19F365143953, to the binary form.  
  
See also: UuidToString, UuidCreate   
  
***  

