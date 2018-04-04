[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetShareSetInfo
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Sets the parameters of a shared resource.
***  


## Code examples:
[How to enumerate, add and delete shares on the local computer (WinNT/XP)](../../samples/sample_351.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetShareSetInfo(
	LPWSTR servername,
	LPWSTR netname,
	DWORD level,
	LPBYTE buf,
	LPDWORD parm_err
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetShareSetInfo IN netapi32;
	STRING servername,;
	STRING netname,;
	LONG lvl,;
	STRING @buf,;
	LONG @parm_err  
```  
***  


## Parameters:
servername 
[in] Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute.

netname 
[in] Pointer to a string that specifies the name of the share to set information on. 

level 
[in] Specifies the information level of the data (1,2,502,...).

buf 
[in] Pointer to the buffer that specifies the data. The format of this data depends on the value of the level parameter.

parm_err 
[out] Pointer to a value that receives the index of the first member of the share information structure that causes the ERROR_INVALID_PARAMETER error.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
If the <Em>servername</Em> parameter is NULL, the local computer is used.  
  
***  

