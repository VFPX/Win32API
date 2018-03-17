<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : NetGroupEnum
Group: Network Management - Library: netapi32    
***  


#### The NetGroupEnum function retrieves information about each global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.
***  


## Code examples:
[Enumerating global and local group accounts on a server (WinNT/XP/2K)](../../samples/sample_411.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetGroupEnum(
  LPCWSTR servername,
  DWORD level,
  LPBYTE* bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  PDWORD_PTR resume_handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetGroupEnum IN netapi32;
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
```txt  
servername
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

level
[in] Specifies the information level of the data.

bufptr
[out] Pointer to the buffer to receive the global group information structure.

prefmaxlen
[in] Specifies the preferred maximum length of the returned data, in bytes.

entriesread
[out] Pointer to a value that receives the count of elements actually enumerated.

totalentries
[out] Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position.

resume_handle
[in, out] Pointer to a variable that contains a resume handle that is used to continue the global group enumeration.  
```  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  

