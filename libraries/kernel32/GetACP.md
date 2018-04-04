[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetACP
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the current ANSI code-page identifier for the system.
***  


## Code examples:
[Retrieving national language settings](../../samples/sample_077.md)  

## Declaration:
```foxpro  
UINT GetACP(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetACP IN kernel32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is the current ANSI code-page identifier for the system, or a default identifier if no code page is current.  
***  

