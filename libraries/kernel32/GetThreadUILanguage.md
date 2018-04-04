[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetThreadUILanguage
Group: [Multilingual User Interface](../../functions_group.md#Multilingual_User_Interface)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
This function has no parameters.  
***  


## Return value:
Returns the identifier for a language explicitly associated with the thread by SetThreadUILanguage or SetThreadPreferredUILanguages  
***  


## Comments:
If no language has been explicitly associated with the current thread, the identifier can indicate a user or system user interface language.  
  
Important: declare returned value as SHORT (2 bytes).  
  
***  

