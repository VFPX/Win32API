[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetShareDel
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Deletes a share name from a server"s list of shared resources, disconnecting all connections to the shared resource.
***  


## Code examples:
[How to enumerate, add and delete shares on the local computer (WinNT/XP)](../../samples/sample_351.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetShareDel(
	LMSTR servername,
	LMSTR netname,
	DWORD reserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetShareDel IN netapi32;
	STRING servername,;
	STRING netname,;
	LONG reserved  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute.

netname 
[in] Pointer to a string that specifies the name of the share to delete.

reserved 
Reserved, must be zero.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
If the <Em>servername</Em> parameter is NULL, the local computer is used.  
  
***  

