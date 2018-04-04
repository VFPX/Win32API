[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetGetConnection
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### The WNetGetConnection function retrieves the name of the network resource associated with a local device.
***  


## Code examples:
[Retrieving the name of the network resource associated with a local device](../../samples/sample_314.md)  
[Mapping and disconnecting network drives](../../samples/sample_387.md)  

## Declaration:
```foxpro  
DWORD WNetGetConnection(
  LPCTSTR lpLocalName,  // local name
  LPTSTR lpRemoteName,  // buffer for remote name
  LPDWORD lpnLength     // buffer size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetGetConnection IN mpr;
	STRING    lpLocalName,;
	STRING  @ lpRemoteName,;
	INTEGER @ lpnLength  
```  
***  


## Parameters:
lpLocalName 
[in] Pointer to a constant null-terminated string that specifies the name of the local device to get the network name for. 

lpRemoteName 
[out] Pointer to a null-terminated character string buffer that receives the remote name used to make the connection. 

lpnLength 
[in/out] Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the lpRemoteName parameter.  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

