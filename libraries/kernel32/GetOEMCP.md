<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetOEMCP
Group: National Language Support - Library: kernel32    
***  


#### Retrieves the current original equipment manufacturer (OEM) code-page identifier for the system.
***  


## Code examples:
[Retrieving national language settings](../../samples/sample_077.md)  

## Declaration:
```foxpro  
UINT GetOEMCP(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetOEMCP IN kernel32  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
The return value is the current OEM code-page identifier for the system or a default identifier if no code page is current.  
***  

