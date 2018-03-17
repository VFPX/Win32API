<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RegCloseKey
Group: Registry - Library: advapi32    
***  


#### The RegCloseKey function releases a handle to the specified registry key.
***  


## Code examples:
[Reading VFP settings from the Windows Registry](../../samples/sample_131.md)  
[How to save registry key including its subkeys and values to a file](../../samples/sample_135.md)  
[Obtaining current Internet Explorer browser version and UserAgent](../../samples/sample_142.md)  
[Saving local machine ODBC Registry Entries to XML file](../../samples/sample_379.md)  
[How to obtain Content-Type value for a file type from the System Registry](../../samples/sample_468.md)  
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegCloseKey(
  HKEY hKey   // handle to key to close
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegCloseKey IN advapi32 INTEGER hKey  
```  
***  


## Parameters:
```txt  
hKey
[in] Handle to the open key to close.  
```  
***  


## Return value:
If the function succeeds, the return value is 0 (ERROR_SUCCESS).  
***  

