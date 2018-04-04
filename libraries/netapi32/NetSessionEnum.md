[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetSessionEnum
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Provides information about sessions established on a server.
***  


## Code examples:
[Enumerating network sessions established on a server](../../samples/sample_505.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetSessionEnum(
  LPWSTR servername,
  LPWSTR UncClientName,
  LPWSTR username,
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
DECLARE INTEGER NetSessionEnum IN Netapi32;
	STRING servername,;
	STRING UncClientName,;
	STRING username,;
	LONG lvl,;
	INTEGER @bufptr,;
	LONG prefmaxlen,;
	LONG @entriesread,;
	LONG @totalentries,;
	LONG @resume_handle  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

UncClientName 
[in] Pointer to a string that specifies the name of the computer session for which information is to be returned. If this parameter is NULL, NetSessionEnum returns information for all computer sessions on the server. 

username 
[in] Pointer to a string that specifies the name of the user for which information is to be returned. If this parameter is NULL, NetSessionEnum returns information for all users. 

level 
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the buffer that receives the data. The format of this data depends on the value of the level parameter.

prefmaxlen 
[in] Specifies the preferred maximum length of returned data, in bytes. 

entriesread 
[out] Pointer to a value that receives the count of elements actually enumerated. 

totalentries 
[out] Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. 

resume_handle 
[in, out] Pointer to a value that contains a resume handle which is used to continue an existing session search.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Buffer <Em>bufptr</Em> is allocated by the system and must be freed using the NetApiBufferFree function.  
  
***  

