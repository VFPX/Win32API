<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WNetAddConnection2
Group: Windows Networking - Library: mpr    
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
```txt  
lpNetResource
[in] Pointer to a NETRESOURCE structure that specifies details of the proposed connection.

lpPassword
[in] Pointer to a constant null-terminated string that specifies a password to be used in making the network connection. Must be NULL for Windows Me/98/95.

lpUsername
[in] Pointer to a constant null-terminated string that specifies a user name for making the connection. Must be NULL for Windows Me/98/95.

dwFlags
[in] Connection options. The following values are currently defined.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

