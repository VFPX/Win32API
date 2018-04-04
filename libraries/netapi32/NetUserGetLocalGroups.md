[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetUserGetLocalGroups
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetUserGetLocalGroups function retrieves a list of local groups to which a specified user belongs.

***  


## Code examples:
[Obtaining names of local and global groups for current user (WinNT/XP/2K)](../../samples/sample_431.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetUserGetLocalGroups(
  LPCWSTR servername,
  LPCWSTR username,
  DWORD level,
  DWORD flags,
  LPBYTE* bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetUserGetLocalGroups IN netapi32;
	STRING    servername,;
	STRING    username,;
	INTEGER   level,;
	INTEGER   flags,;
	INTEGER @ bufptr,;
	INTEGER   prefmaxlen,;
	INTEGER @ entriesread,;
	INTEGER @ totalentries
  
```  
***  


## Parameters:
servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute.

username 
[in] Pointer to a constant string that specifies the name of the user for which to return local group membership information.

level 
[in] Specifies the information level of the data.

flags 
[in] Specifies a bitmask of flags.

bufptr 
[out] Pointer to the buffer that receives the data.

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes.

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a value that receives the total number of entries that could have been enumerated.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  

