[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetMessageNameEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Lists the message aliases that receive messages on a specified computer. The function requires that the messenger service be started.

***  


## Code examples:
[Using the NetMessageBufferSend to send messages on the network](../../samples/sample_494.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetMessageNameEnum(
	LPCWSTR servername,
	DWORD level,
	LPBYTE* bufptr,
	DWORD prefmaxlen,
	LPDWORD entriesread,
	LPDWORD totalentries,
	LPDWORD resume_handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetMessageNameEnum IN netapi32;
	STRING    servername,;
	INTEGER   lvl,;
	INTEGER @ bufptr,;
	INTEGER   prefmaxlen,;
	INTEGER @ entriesread,;
	INTEGER @ totalentries,;
	INTEGER   resume_handle  
```  
***  


## Parameters:
servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

level 
Set to zero.

bufptr 
[out] Pointer to the buffer that receives the data

prefmaxlen 
[in] Specifies the preferred maximum length of the returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required for the data.

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 
totalentries 

[out] Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position.

resume_handle 
[in, out] Pointer to a value that contains a resume handle which is used to continue an existing message alias search.

  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
The <Em>bufptr</Em> allocated by the system and must be freed using the NetApiBufferFree function.  
  
Only members of the Administrators local group can successfully execute the NetMessageNameEnum function on a remote server.  
  
Note that this is Unicode function.  
  
See also: [NetMessageNameAdd](../netapi32/NetMessageNameAdd.md), [NetMessageNameDel](../netapi32/NetMessageNameDel.md).  
  
***  

