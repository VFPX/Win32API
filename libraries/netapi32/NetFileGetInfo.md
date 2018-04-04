[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetFileGetInfo
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetFileGetInfo function retrieves information about a particular opening of a server resource.
***  


## Declaration:
```foxpro  
NET_API_STATUS NetFileGetInfo(
  LPWSTR servername,
  DWORD fileid,
  DWORD level,
  LPBYTE* bufptr
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetFileGetInfo IN netapi32;
	STRING    servername,;
	INTEGER   fileid,;
	INTEGER   lvl,;
	STRING  @ bufptr
  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used. 

fileid 
[in] Specifies the file identifier of the open resource for which to return information. 

level 
[in] Specifies the information level of the data.

bufptr 
[out] Pointer to the address of the buffer that receives the information.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
You can call the NetFileEnum function to retrieve information about multiple files open on a server.  
  
***  

