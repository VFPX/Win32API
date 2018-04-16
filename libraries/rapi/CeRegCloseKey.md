[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeRegCloseKey
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function releases the handle of the specified key.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  

## Declaration:
```foxpro  
LONG CeRegCloseKey(
  HKEY hKey
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeRegCloseKey IN rapi;
	INTEGER hKey  
```  
***  


## Parameters:
hKey 
[in] Handle to the open key to close.   
***  


## Return value:
ERROR_SUCCESS (0) indicates success.  
***  


## Comments:
The handle for a specified key should not be used after it has been closed, because it will no longer be valid. Key handles should not be left open any longer than necessary.   
  
The CeRegCloseKey function always writes information to the registry before returning, eliminating the need to flush keys in the Windows CE registry.  
  
See also: [CeRegOpenKeyEx](CeRegOpenKeyEx.md) function.  
  
***  

