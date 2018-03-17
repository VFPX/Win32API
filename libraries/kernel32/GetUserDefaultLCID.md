<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetUserDefaultLCID
Group: National Language Support - Library: kernel32    
***  


#### Retrieves the user default–locale identifier.
***  


## Code examples:
[Retrieving national language settings](../../samples/sample_077.md)  

## Declaration:
```foxpro  
LCID GetUserDefaultLCID(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetUserDefaultLCID IN kernel32  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
On single-user systems, the return value is the same as that returned by GetSystemDefaultLCID.  
***  

