
## Function name : SetProcessPreferredUILanguages
Group: Multilingual User Interface - Library: kernel32    
***  


#### Sets the process preferred UI languages for the application process.
***  


## Declaration:
```foxpro  
BOOL SetProcessPreferredUILanguages(
  _In_       DWORD dwFlags,
  _In_opt_   PCZZWSTR pwszLanguagesBuffer,
  _Out_opt_  PULONG pulNumLanguages
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetProcessPreferredUILanguages IN kernel32;
	INTEGER dwFlags,;
	STRING @pwszLanguagesBuffer,;
	INTEGER @pulNumLanguages  
```  
***  


## Parameters:
dwFlags [in]
Flags identifying the language format to use for the process preferred UI languages.

pwszLanguagesBuffer [in, optional]
Pointer to a double null-terminated multi-string buffer that contains an ordered, null-delimited list in decreasing order of preference.

pulNumLanguages [out, optional]
Pointer to the number of languages that has been set in the process language list from the input buffer, up to a maximum of five.  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  


## Comments:
By default, a VFP process does not have any preferred UI languages set.  
  
MSDN: Ideally, applications will call SetProcessPreferredUILanguages as soon as possible after launching. Use of MUI_LANGUAGE_NAME is recommended over MUI_LANGUAGE_ID.  
  
See also: GetProcessPreferredUILanguages   
  
***  

