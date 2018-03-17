<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RpcStringFree
Group: Remote Procedure Call (RPC) - Library: rpcrt4    
***  


#### Frees a character string allocated by the RPC run-time library.
***  


## Code examples:
[Generating random UUID values](../../samples/sample_024.md)  
[Generating sequential UUID values](../../samples/sample_587.md)  
[Generating UUID values from numbers](../../samples/sample_588.md)  

## Declaration:
```foxpro  
RPC_STATUS RPC_ENTRY RpcStringFree(
	unsigned char **String
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RpcStringFree IN Rpcrt4;
	LONG @StringUuid  
```  
***  


## Parameters:
```txt  
String
Pointer to a pointer to the character string to free.  
```  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
An application is responsible for calling RpcStringFree once for each character string allocated and returned by calls to other RPC run-time library routines.  
  
See also: UuidToString   
  
***  

