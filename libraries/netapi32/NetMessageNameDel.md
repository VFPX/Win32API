[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetMessageNameDel
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Deletes a message alias in the message name table. The function requires that the messenger service be started.
***  


## Code examples:
[Using the NetMessageBufferSend to send messages on the network](../../samples/sample_494.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetMessageNameDel(
	LPCWSTR servername,
	LPCWSTR msgname
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetMessageNameDel IN netapi32;
	STRING servername,;
	STRING msgname
  
```  
***  


## Parameters:
servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

msgname 
[in] Pointer to a constant string that specifies the message alias to delete. The string cannot be more than 15 characters long.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
See also: [NetMessageNameEnum](../netapi32/NetMessageNameEnum.md), [NetMessageNameAdd](../netapi32/NetMessageNameAdd.md).  
  
***  

