[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetKeyboardType
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves information about the current keyboard.
***  


## Code examples:
[Current keyboard type](../../samples/sample_095.md)  

## Declaration:
```foxpro  
int GetKeyboardType(
  int nTypeFlag  // information type
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetKeyboardType IN user32 INTEGER nTypeFlag  
```  
***  


## Parameters:
nTypeFlag 
[in] Specifies the type of keyboard information to be retrieved.  
***  


## Return value:
If the function succeeds, the return value specifies the requested information.  
***  

