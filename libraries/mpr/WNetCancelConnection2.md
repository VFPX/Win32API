[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetCancelConnection2
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### The WNetCancelConnection2 function cancels an existing network connection. You can also call the function to remove remembered network connections that are not currently connected.
***  


## Code examples:
[Mapping and disconnecting network drives](../../samples/sample_387.md)  

## Declaration:
```foxpro  
DWORD WNetCancelConnection2(
  LPCTSTR lpName,
  DWORD dwFlags,
  BOOL fForce
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetCancelConnection2 IN mpr;
	STRING  lpName,;
	INTEGER dwFlags,;
	INTEGER fForce  
```  
***  


## Parameters:
lpName 
[in] Pointer to a constant null-terminated string that specifies the name of either the redirected local device or the remote network resource to disconnect from.

dwFlags 
[in] Connection type. 

fForce 
[in] Specifies whether the disconnection should occur if there are open files or jobs on the connection.  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

