[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetUserEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetUserEnum function provides information about all user accounts on a server. 
***  


## Code examples:
[Obtaining information about all user accounts on a server (WinNT only)](../../samples/sample_249.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetUserEnum(
  LPCWSTR servername,
  DWORD level,
  DWORD filter,
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
DECLARE INTEGER NetUserEnum IN netapi32;
	STRING    servername,;
	INTEGER   level,;
	INTEGER   filter,;
	INTEGER @ bufptr,;
	INTEGER   prefmaxlen,;
	INTEGER @ entriesread,;
	INTEGER @ totalentries,;
	INTEGER @ resume_handle  
```  
***  


## Parameters:
servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used. 

level 
[in] Specifies the information level of the data. 

filter 
[in] Specifies a value that filters the account types for enumeration. A value of zero indicates all account types. 

bufptr 
[out] Pointer to the buffer that receives the data. 

prefmaxlen 
[in] Specifies the preferred maximum length, in 8-bit bytes of returned data. 

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. 

resume_handle 
[in/out] Pointer to a value that contains a resume handle which is used to continue an existing user search.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0). If the function fails, the return value is an error code.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.1 and later.  
Windows 95/98/Me: Unsupported.  
  
If you call NetUserEnum and specify information level 1, 2, 3, or 4, the password member of each structure is set to NULL to maintain password security.   
  
To quickly enumerate user, computer, or global group account information, call the NetQueryDisplayInformation function.   
  
***  

