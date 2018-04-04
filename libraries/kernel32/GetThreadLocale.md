[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetThreadLocale
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the calling thread"s current locale.
***  


## Code examples:
[Retrieving national language settings](../../samples/sample_077.md)  

## Declaration:
```foxpro  
LCID GetThreadLocale(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetThreadLocale IN kernel32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
When a thread is created, it uses the system default user locale.  
***  

