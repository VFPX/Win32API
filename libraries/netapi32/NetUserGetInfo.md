<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : NetUserGetInfo
Group: Network Management - Library: netapi32    
***  


#### Retrieves information about a particular user account on a server.
***  


## Code examples:
[Adding and deleting User Accounts](../../samples/sample_478.md)  
[Finding out if the current user is the Guest account](../../samples/sample_566.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetUserGetInfo(
  LPCWSTR servername,
  LPCWSTR username,
  DWORD level,
  LPBYTE* bufptr
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetUserGetInfo IN netapi32;
	STRING    servername,;
	STRING    username,;
	INTEGER   lvl,;
	INTEGER @ bufptr
  
```  
***  


## Parameters:
```txt  
servername
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

username
[in] Pointer to a constant string that specifies the name of the user account for which to return information.

level
[in] Specifies the information level of the data.

bufptr
[out] Pointer to the buffer that receives the data.  
```  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Important: the <Em>bufptr</Em> is allocated by the system and must be freed using the NetApiBufferFree function.  
  
See also: NetUserSetInfo, NetUserGetGroups, NetUserEnum.  
  
***  

