[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetServerGetInfo
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetServerGetInfo function retrieves current configuration information for the specified server.
***  


## Code examples:
[Retrieving configuration information for the specified server (Win98/Me)](../../samples/sample_276.md)  
[Retrieving configuration information for the specified server (Win2000/XP)](../../samples/sample_425.md)  

## Declaration:
```foxpro  
Windows NT/2000/XP:
NET_API_STATUS NetServerGetInfo(
  LPWSTR servername,
  DWORD level,
  LPBYTE *bufptr
);

Windows 95/98/Me:
extern API_FUNCTION
 NetServerGetInfo(
  const char FAR * pszServer,
  short sLevel,
  char FAR * pbBuffer,
  unsigned short cbBuffer,
  unsigned short FAR * pcbTotalAvail
);  
```  
***  


## FoxPro declaration:
```foxpro  
Windows NT/2000/XP:
DECLARE INTEGER NetServerGetInfo IN netapi32;
	STRING    servername,;
	INTEGER   level,;
	STRING  @ bufptr

Windows 95/98/Me:
DECLARE INTEGER NetServerGetInfo IN svrapi;
	STRING    pszServer,;
	INTEGER   sLevel,;
	STRING  @ pbBuffer,;
	SHORT     cbBuffer,;
	SHORT   @ pcbTotalAvail  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used. 

level 
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the buffer that receives the data. The format of this data depends on the value of the level parameter.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0). Otherwise the return value can be one of the predefined error codes.  
***  

