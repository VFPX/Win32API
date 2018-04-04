[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetGetNetworkInformation
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
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
lpProvider 
[in] Pointer to a constant null-terminated string that contains the name of the network provider for which information is required. 

lpNetInfoStruct 
[out] Pointer to a NETINFOSTRUCT structure. The structure describes characteristics of the network.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

