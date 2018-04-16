[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetApiBufferFree
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Frees the memory that the NetApiBufferAllocate function allocates. Call NetApiBufferFree to free the memory that other network management functions return on Windows NT, Windows 2000, and Windows XP.
***  


## Code examples:
[Enumerating files opened on the network](../../samples/sample_121.md)  
[Enumerating servers of the specified type (e.g. SQL Server) in the primary domain](../../samples/sample_165.md)  
[Retrieving the name of the primary domain controller (PDC) and join status information](../../samples/sample_166.md)  
[Retrieving information about all users currently logged on to the workstation (WinNT only)](../../samples/sample_167.md)  
[Enumerating connections made to a shared resource for the local computer (WinNT only)](../../samples/sample_168.md)  
[Obtaining information about all user accounts on a server (WinNT only)](../../samples/sample_249.md)  
[How to enumerate, add and delete shares on the local computer (WinNT/XP)](../../samples/sample_351.md)  
[Enumerating global and local group accounts on a server (WinNT/XP/2K)](../../samples/sample_411.md)  
[Retrieving configuration information for the specified server (Win2000/XP)](../../samples/sample_425.md)  
[Obtaining names of local and global groups for current user (WinNT/XP/2K)](../../samples/sample_431.md)  
[Using NetWkstaTransportEnum to obtain MAC Address of remote server](../../samples/sample_435.md)  
[Retrieving configuration information for the specified workstation (Win2000/XP)](../../samples/sample_436.md)  
[Adding and deleting User Accounts](../../samples/sample_478.md)  
[Adding and deleting Scheduled Tasks using NetScheduleJob API functions](../../samples/sample_490.md)  
[Using the NetMessageBufferSend to send messages on the network](../../samples/sample_494.md)  
[Enumerating network sessions established on a server](../../samples/sample_505.md)  
[Finding out if the current user is the Guest account](../../samples/sample_566.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetApiBufferFree(
  LPVOID Buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetApiBufferFree IN netapi32;
	INTEGER Buffer  
```  
***  


## Parameters:
Buffer 
[in] Pointer to a buffer returned previously by another network management function.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0). If the function fails, the return value is a system error code.   
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.1 and later.  
Windows 95/98/Me: Unsupported.  
  
Various NetApi functions  
* NetServerEnum   
* NetConnectionEnum   
* NetUserEnum   
* NetWkstaUserEnum   
* NetShareEnum   
* NetGetDCName   
* NetGroupEnum   
* NetLocalGroupEnum   
*and more...*  

implicitly allocate a memory buffer and require it to be freed after the call is complete.  
  
***  

