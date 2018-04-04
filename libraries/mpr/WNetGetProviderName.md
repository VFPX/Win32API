[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetGetProviderName
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### The WNetGetProviderName function obtains the provider name for a specific type of network. 
***  


## Code examples:
[Obtaining provider name for a specific type of network](../../samples/sample_311.md)  

## Declaration:
```foxpro  
DWORD WNetGetProviderName(
  DWORD dwNetType,       // network type
  LPTSTR lpProviderName, // provider name buffer
  LPDWORD lpBufferSize   // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetGetProviderName IN mpr;
	INTEGER   dwNetType,;
	STRING  @ lpProviderName,;
	INTEGER @ lpBufferSize
  
```  
***  


## Parameters:
dwNetType 
[in] Specifies the network type that is unique to the network.

lpProviderName 
[out] Pointer to a buffer in which to return the network provider name. 

lpBufferSize 
[in/out] Specifies the size, in characters, of the buffer passed to the function.  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).   
***  


## Comments:
You can find a complete list of network types in the header file Winnetwk.h.  
  
***  

