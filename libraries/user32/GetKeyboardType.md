<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetKeyboardType
Group: System Information - Library: user32    
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
```txt  
nTypeFlag
[in] Specifies the type of keyboard information to be retrieved.  
```  
***  


## Return value:
If the function succeeds, the return value specifies the requested information.  
***  

