[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetGetDCName
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Returns the name of the primary domain controller (PDC). It does not return the name of the backup domain controller (BDC) for the specified domain.
***  


## Code examples:
[Retrieving the name of the primary domain controller (PDC) and join status information](../../samples/sample_166.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetGetDCName(
  LPCWSTR servername,
  LPCWSTR domainname,
  LPBYTE *bufptr
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetGetDCName IN netapi32;
	STRING    servername,;
	STRING    domainname,;
	INTEGER @ bufptr  
```  
***  


## Parameters:
servername 
[in] Pointer to a constant Unicode string specifying the name of the remote server on which the function is to execute. 

domainname 
[in] Pointer to a constant Unicode string specifying the name of the domain. 

bufptr 
[out] Pointer to an allocated buffer that receives a Unicode string which specifies the server name of the PDC of the domain.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.1 and later.  
Windows 95/98/Me: Unsupported.  
  
This buffer is allocated by the system and must be freed using the NetApiBufferFree function.   
  
***  

