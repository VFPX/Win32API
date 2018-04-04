[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetServerEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Lists all servers of the specified type that are visible in a domain.
***  


## Code examples:
[Enumerating servers of the specified type (e.g. SQL Server) in the primary domain](../../samples/sample_165.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetServerEnum(
  LPCWSTR servername,
  DWORD level,
  LPBYTE *bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  DWORD servertype,
  LPCWSTR domain,
  LPDWORD resume_handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetServerEnum IN netapi32;
	INTEGER   servername,;
	INTEGER   level,;
	INTEGER @ bufptr,;
	INTEGER   prefmaxlen,;
	INTEGER @ entriesread,;
	INTEGER @ totalentries,;
	INTEGER   servertype,;
	STRING    domain,;
	INTEGER   resume_handle  
```  
***  


## Parameters:
servername 
[in] Reserved; must be NULL. 

level 
[in] Specifies the information level of the data. 

bufptr 
[out] Pointer to the buffer that receives the data. 

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes. 

entriesread 
[out] Pointer to a DWORD value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a DWORD value that receives the total number of visible servers and workstations on the network. 

servertype 
[in] Specifies a DWORD value that filters the server entries to return from the enumeration. 
domain 
[in] Pointer to a constant Unicode string specifying the name of the domain for which a list of servers is to be returned. 

resume_handle 
Reserved; must be set to zero.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
For example, an application can call NetServerEnum to list all domain controllers only or all SQL servers only. You can combine bit masks to list several types. For example, a value of 0x00000003 combines the bit masks for SV_TYPE_WORKSTATION (0x00000001) and SV_TYPE_SERVER (0x00000002).  
  
The buffer within this function is allocated by the system and must be freed using the NetApiBufferFree function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.   
  
If you require more information for a specific server, call the WNetEnumResource function.  
  
Windows NT/2000/XP: Included in Windows NT 3.1 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

