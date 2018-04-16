[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetConnectionEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Lists all connections made to a shared resource on the server or all connections established from a particular computer.
***  


## Code examples:
[Enumerating connections made to a shared resource for the local computer (WinNT only)](../../samples/sample_168.md)  

## Declaration:
```foxpro  
WinNT:
NET_API_STATUS NetConnectionEnum(
  LPWSTR servername,
  LPWSTR qualifier,
  DWORD level,
  LPBYTE *bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  LPDWORD resume_handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
WinNT:
DECLARE INTEGER NetConnectionEnum IN netapi32;
	INTEGER   servername,;
	STRING    qualifier,;
	INTEGER   level,;
	INTEGER @ bufptr,;
	INTEGER   prefmaxlen,;
	INTEGER @ entriesread,;
	INTEGER @ totalentries,;
	INTEGER @ resume_handle  
```  
***  


## Parameters:
servername 
[in] Pointer to a Unicode (Windows NT/2000/XP) or ANSI (Windows 95/98/Me) string specifying the name of the remote server on which the function is to execute. 

qualifier 
[in] Pointer to a Unicode (Windows NT/2000/XP) or ANSI (Windows 95/98/Me) string specifying a share name or computer name for the connections of interest. 

level 
[in] Specifies the information level of the data. 

bufptr 
[out] Pointer to the address of the buffer that receives the information. 

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes. 

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 
totalentries 

[out] Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. 

resume_handle 
[in/out] Pointer to a DWORD value that contains a resume handle which is used to continue an existing connection search.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0). If the function fails, the return value is a system error code. 
  
***  


## Comments:
Admin or server, print, or comm operator group membership is required to successfully execute the NetConnectionEnum function.  
  
Different declarations for Windows NT/2000/XP, and for Windows 95/98/Me.  
Windows 95/98/Me: The caller must allocate and deallocate the buffer -- <Strong>bufptr</Strong>.  
  

***  

