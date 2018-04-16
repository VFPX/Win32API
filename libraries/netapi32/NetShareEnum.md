[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetShareEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetShareEnum function retrieves information about each shared resource on a server or the local computer.
***  


## Code examples:
[How to enumerate, add and delete shares on the local computer (WinNT/XP)](../../samples/sample_351.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetShareEnum(
  LPWSTR servername,
  DWORD level,
  LPBYTE* bufptr,
  DWORD prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  LPDWORD resume_handle
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetShareEnum IN netapi32;
	STRING    servername,;
	LONG      lvl,;
	INTEGER @ bufptr,;
	LONG      prefmaxlen,;
	LONG    @ entriesread,;
	LONG    @ totalentries,;
	LONG      resume_handle  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used. 

level 
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the buffer that receives the data. The format of this data depends on the value of the level parameter.

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes.

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a value that receives the total number of entries that could have been enumerated. 

resume_handle 
[in, out] Pointer to a value that contains a resume handle which is used to continue an existing share search.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
You can also use the WNetEnumResource function to retrieve resource information.  
  
Windows 95/98/Me:  The parameters for Windows 95/98/Me are different from those for Windows NT/2000/XP.  
  
<Em>bufptr</Em>  
Windows NT/2000/XP:  This buffer is allocated by the system and must be freed using the NetApiBufferFree function.  
Windows 95/98/Me:  The caller must allocate and deallocate this buffer.  
  
.  
  
***  

