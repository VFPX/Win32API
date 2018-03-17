<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetThreadLocale
Group: National Language Support - Library: kernel32    
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
```txt  
This function has no parameters.  
```  
***  


## Return value:
When a thread is created, it uses the system default user locale.  
***  

