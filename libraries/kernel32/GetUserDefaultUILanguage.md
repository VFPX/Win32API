[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUserDefaultUILanguage
Group: [Multilingual User Interface](../../functions_group.md#Multilingual_User_Interface)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
This function has no parameters.  
***  


## Return value:
Returns the language identifier for the user UI language for the current user.  
***  


## Comments:
If the current user has not set a language, GetUserDefaultUILanguage returns the preferred language set for the system.   
  
If there is no preferred language set for the system, then the system default UI language (also known as "install language") is returned.  
  
Important: declare returned value as SHORT (2 bytes).  
  
***  

