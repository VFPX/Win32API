<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetUserDefaultUILanguage
Group: Multilingual User Interface - Library: kernel32    
***  


#### Returns the language identifier for the user UI language for the current user.
***  


## Declaration:
```foxpro  
LANGID GetUserDefaultUILanguage(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetUserDefaultUILanguage IN kernel32  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
Returns the language identifier for the user UI language for the current user.  
***  


## Comments:
If the current user has not set a language, GetUserDefaultUILanguage returns the preferred language set for the system.   
  
If there is no preferred language set for the system, then the system default UI language (also known as "install language") is returned.  
  
Important: declare returned value as SHORT (2 bytes).  
  
***  

