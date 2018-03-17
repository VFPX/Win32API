<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetUserDefaultLangID
Group: National Language Support - Library: kernel32    
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
```txt  
This function has no parameters.  
```  
***  


## Return value:
The return value is not necessarily the same as that returned by GetSystemDefaultLangID, even if the computer is a single-user system.  
***  

