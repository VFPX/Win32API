[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetWkstaTransportEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetWkstaTransportEnum function supplies information about transport protocols that are managed by the redirector, which is the software on the client computer that generates file requests to the server computer.
***  


## Code examples:
[Using NetWkstaTransportEnum to obtain MAC Address of remote server](../../samples/sample_435.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetWkstaTransportEnum(
  LPWSTR servername,
  DWORD level,
  LPBYTE* bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  LPDWORD resumehandle
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetWkstaTransportEnum IN netapi32;
	STRING    servername,;
	LONG      lvl,;
	INTEGER @ bufptr,;
	LONG      prefmaxlen,;
	LONG    @ entriesread,;
	LONG    @ totalentries,;
	LONG      resumehandle  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used. 

level 
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the buffer that receives the data.

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required for the data.

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

resumehandle 
[in, out] Pointer to a value that contains a resume handle which is used to continue an existing workstation transport search. The handle should be zero on the first call and left unchanged for subsequent calls.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  

