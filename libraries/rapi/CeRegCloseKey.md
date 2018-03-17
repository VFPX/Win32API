<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeRegCloseKey
Group: Remote Application Programming (RAPI) - Library: rapi    
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
```txt  
hKey
[in] Handle to the open key to close.  
```  
***  


## Return value:
ERROR_SUCCESS (0) indicates success.  
***  


## Comments:
The handle for a specified key should not be used after it has been closed, because it will no longer be valid. Key handles should not be left open any longer than necessary.   
  
The CeRegCloseKey function always writes information to the registry before returning, eliminating the need to flush keys in the Windows CE registry.  
  
See also CeRegOpenKeyEx function.  
  
***  

