<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : NetMessageNameAdd
Group: Network Management - Library: netapi32    
***  


#### Registers a message alias in the message name table. The function requires that the messenger service be started.

***  


## Code examples:
[Using the NetMessageBufferSend to send messages on the network](../../samples/sample_494.md)  

## Declaration:
```foxpro  
NNET_API_STATUS NetMessageNameAdd(
	LPCWSTR servername,
	LPCWSTR msgname
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetMessageNameAdd IN netapi32;
	STRING servername,;
	STRING msgname  
```  
***  


## Parameters:
```txt  
servername
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

msgname
[in] Pointer to a constant string that specifies the message alias to add. The string cannot be more than 15 characters long.  
```  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
See also: NetMessageNameEnum, NetMessageNameDel.  
  
***  

