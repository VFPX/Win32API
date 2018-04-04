[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetAddConnection2
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### The WNetAddConnection2 function makes a connection to a network resource. The function can redirect a local device to the network resource.
***  


## Code examples:
[Mapping and disconnecting network drives](../../samples/sample_387.md)  

## Declaration:
```foxpro  
DWORD WNetAddConnection2(
  LPNETRESOURCE lpNetResource,
  LPCTSTR lpPassword,
  LPCTSTR lpUsername,
  DWORD dwFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetAddConnection2 IN mpr;
	STRING @ lpNetResource,;
	STRING   lpPassword,;
	STRING   lpUsername,;
	INTEGER  dwFlags
  
```  
***  


## Parameters:
lpNetResource 
[in] Pointer to a NETRESOURCE structure that specifies details of the proposed connection.

lpPassword 
[in] Pointer to a constant null-terminated string that specifies a password to be used in making the network connection. Must be NULL for Windows Me/98/95.

lpUsername 
[in] Pointer to a constant null-terminated string that specifies a user name for making the connection. Must be NULL for Windows Me/98/95.

dwFlags 
[in] Connection options. The following values are currently defined.  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

