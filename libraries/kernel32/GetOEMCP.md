[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetOEMCP
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
This function has no parameters.  
***  


## Return value:
The return value is the current OEM code-page identifier for the system or a default identifier if no code page is current.  
***  

