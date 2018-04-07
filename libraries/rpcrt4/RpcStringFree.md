[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RpcStringFree
Group: [Remote Procedure Call (RPC)](../../functions_group.md#Remote_Procedure_Call_(RPC))  -  Library: [rpcrt4](../../Libraries.md#rpcrt4)  
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
String
Pointer to a pointer to the character string to free.  
***  


## Return value:
Returns RPC_S_OK (0) if the call succeeded.  
***  


## Comments:
An application is responsible for calling RpcStringFree once for each character string allocated and returned by calls to other RPC run-time library routines.  
  
See also: [UuidToString](../rpcrt4/UuidToString.md).  
  
***  

