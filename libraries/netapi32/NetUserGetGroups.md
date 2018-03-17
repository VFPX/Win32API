<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : NetUserGetGroups
Group: Network Management - Library: netapi32    
***  


#### The NetUserGetGroups function retrieves a list of global groups to which a specified user belongs.
***  


## Code examples:
[Obtaining names of local and global groups for current user (WinNT/XP/2K)](../../samples/sample_431.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetUserGetGroups(
  LPCWSTR servername,
  LPCWSTR username,
  DWORD level,
  LPBYTE* bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetUserGetGroups IN netapi32;
	STRING    servername,;
	STRING    username,;
	INTEGER   lvl,;
	INTEGER @ bufptr,;
	INTEGER   prefmaxlen,;
	INTEGER @ entriesread,;
	INTEGER @ totalentries
  
```  
***  


## Parameters:
```txt  
servername
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute.

username
[in] Pointer to a constant string that specifies the name of the user to search for in each group account.

level
[in] Specifies the information level of the data.

bufptr
[out] Pointer to the buffer that receives the data. This buffer is allocated by the system and must be freed using the NetApiBufferFree function.

prefmaxlen
[in] Specifies the preferred maximum length of returned data, in bytes.

entriesread
[out] Pointer to a value that receives the count of elements actually retrieved.

totalentries
[out] Pointer to a value that receives the total number of entries that could have been retrieved.  
```  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  

