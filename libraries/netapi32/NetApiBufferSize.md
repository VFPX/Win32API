[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetApiBufferSize
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetApiBufferSize function returns the size, in bytes, of a buffer allocated by a call to the NetApiBufferAllocate function.
***  


## Code examples:
[Retrieving the name of the primary domain controller (PDC) and join status information](../../samples/sample_166.md)  
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
NET_API_STATUS NetApiBufferSize(
  LPVOID Buffer,
  LPDWORD ByteCount
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetApiBufferSize IN netapi32;
	INTEGER   Buffer,;
	INTEGER @ ByteCount  
```  
***  


## Parameters:
Buffer 
[in] Pointer to a buffer returned by the NetApiBufferAllocate function. 

ByteCount 
[out] Receives the size of the buffer, in bytes.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
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

