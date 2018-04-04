[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetWkstaGetInfo
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetWkstaGetInfo function returns information about the configuration of a workstation.
***  


## Code examples:
[Retrieving configuration information for the specified workstation (Win2000/XP)](../../samples/sample_436.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetWkstaGetInfo(
  LPWSTR servername,
  DWORD level,
  LPBYTE* bufptr
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetWkstaGetInfo IN netapi32;
	STRING    servername,;
	INTEGER   lvl,;
	INTEGER @ bufptr  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

level 
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the buffer that receives the data.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  

