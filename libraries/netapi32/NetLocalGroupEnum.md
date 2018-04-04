[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetLocalGroupEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetLocalGroupEnum function returns information about each local group account on the specified server.
***  


## Code examples:
[Enumerating global and local group accounts on a server (WinNT/XP/2K)](../../samples/sample_411.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetLocalGroupEnum(
  LPCWSTR servername,
  DWORD level,
  LPBYTE* bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  PDWORD_PTR resumehandle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetLocalGroupEnum IN netapi32;
	STRING    srvname,;
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
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the address of the buffer that receives the information structure.

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes.

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a value that receives the approximate total number of entries that could have been enumerated from the current resume position. 

resumehandle 
[in, out] Pointer to a value that contains a resume handle that is used to continue an existing local group search.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  

