[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetFileClose
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetFileClose function forces a resource to close.
***  


## Declaration:
```foxpro  
NET_API_STATUS NetFileClose(
	LMSTR servername,
	DWORD fileid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTGER NetFileClose IN netapi32;
	STRING servername,;
	LONG fileid
  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute.

fileid 
[in] Specifies the file identifier of the opened resource instance to close.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
This function can be used when an error prevents closure by any other means. You should use NetFileClose with caution because it does not write data cached on the client system to the file before closing the file.  
  
If <Em>servername</Em> parameter is NULL, the local computer is used.   
  
See also: [NetFileEnum](../netapi32/NetFileEnum.md), [NetFileGetInfo](../netapi32/NetFileGetInfo.md).  
  
***  

