[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetWkstaUserEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetWkstaUserEnum function lists information about all users currently logged on to the workstation. This list includes interactive, service and batch logons.
***  


## Code examples:
[Retrieving information about all users currently logged on to the workstation (WinNT only)](../../samples/sample_167.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetWkstaUserEnum(
  LPWSTR servername,
  DWORD level,
  LPBYTE *bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  LPDWORD resumehandle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetWkstaUserEnum IN netapi32;
	STRING    servername,;
	INTEGER   level,;
	INTEGER @ bufptr,;
	INTEGER   prefmaxlen,;
	INTEGER @ entriesread,;
	INTEGER @ totalentries,;
	INTEGER @ resumehandle  
```  
***  


## Parameters:
servername 
[in] Pointer to a Unicode string specifying the name of the remote server on which the function is to execute. 

level 
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the buffer that receives the data. 

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes. If you specify MAX_PREFERRED_LENGTH (-1), the function allocates the amount of memory required for the data. 

entriesread 
[out] Pointer to a DWORD value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a DWORD value that receives the total number of entries that could have been enumerated from the current resume position. 

resumehandle 
[in/out] Pointer to a DWORD value that contains a resume handle which is used to continue an existing search.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.1 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

