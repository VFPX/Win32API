[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WNetCloseEnum
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [mpr](../../Libraries.md#mpr)  
***  


#### The WNetCloseEnum function ends a network resource enumeration started by a call to the WNetOpenEnum function.
***  


## Code examples:
[Enumerating network resources](../../samples/sample_313.md)  

## Declaration:
```foxpro  
DWORD WNetCloseEnum(
  HANDLE hEnum   // handle to enumeration
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WNetCloseEnum IN mpr;
	INTEGER hEnum  
```  
***  


## Parameters:
hEnum 
[in] Specifies a handle that identifies an enumeration instance. This handle must be returned by the WNetOpenEnum function.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.   
***  

