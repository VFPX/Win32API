<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetThreadUILanguage
Group: Multilingual User Interface - Library: kernel32    
***  


#### Returns the language identifier of the first user interface language for the current thread.
***  


## Declaration:
```foxpro  
LANGID GetThreadUILanguage(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetThreadUILanguage IN kernel32  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
Returns the identifier for a language explicitly associated with the thread by SetThreadUILanguage or SetThreadPreferredUILanguages  
***  


## Comments:
If no language has been explicitly associated with the current thread, the identifier can indicate a user or system user interface language.  
  
Important: declare returned value as SHORT (2 bytes).  
  
***  

