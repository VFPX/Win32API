<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WNetGetNetworkInformation
Group: Windows Networking - Library: mpr    
***  


#### The WNetGetNetworkInformation function returns extended information about a specific network provider whose name was returned by a previous network enumeration.
***  


## Code examples:
[Retrieving Network Provider information](../../samples/sample_315.md)  

## Declaration:
```foxpro  
DWORD WNetGetNetworkInformation(
  LPCTSTR lpProvider,              // provider name
  LPNETINFOSTRUCT lpNetInfoStruct  // network information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetGetNetworkInformation IN mpr;
	STRING   lpProvider,;
	STRING @ lpNetInfoStruct  
```  
***  


## Parameters:
```txt  
lpProvider
[in] Pointer to a constant null-terminated string that contains the name of the network provider for which information is required.

lpNetInfoStruct
[out] Pointer to a NETINFOSTRUCT structure. The structure describes characteristics of the network.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

