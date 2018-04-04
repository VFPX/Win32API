[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUserDefaultLangID
Group: [National Language Support](../../functions_group.md#National_Language_Support)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the language identifier of the current user locale.
***  


## Code examples:
[Retrieving national language settings](../../samples/sample_077.md)  

## Declaration:
```foxpro  
LANGID GetUserDefaultLangID(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetUserDefaultLangID IN kernel32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is not necessarily the same as that returned by GetSystemDefaultLangID, even if the computer is a single-user system.  
***  

