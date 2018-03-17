<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetProcessPreferredUILanguages
Group: Multilingual User Interface - Library: kernel32    
***  


#### Retrieves the process preferred UI languages.
***  


## Declaration:
```foxpro  
BOOL GetProcessPreferredUILanguages(
  _In_       DWORD dwFlags,
  _Out_      PULONG pulNumLanguages,
  _Out_opt_  PZZWSTR pwszLanguagesBuffer,
  _Inout_    PULONG pcchLanguagesBuffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProcessPreferredUILanguages IN kernel32;
	INTEGER dwFlags,;
	INTEGER @pulNumLanguages,;
	STRING @pwszLanguagesBuffer,;
	INTEGER @pcchLanguagesBuffer  
```  
***  


## Parameters:
```txt  
dwFlags [in]
Flags identifying the language format to use for the process preferred UI languages.

pulNumLanguages [out]
Pointer to the number of languages retrieved in pwszLanguagesBuffer.

pwszLanguagesBuffer [out, optional]
Optional. Pointer to a double null-terminated multi-string buffer in which the function retrieves an ordered, null-delimited list in preference order, starting with the most preferable.

pcchLanguagesBuffer [in, out]
Pointer to the size, in characters, for the language buffer indicated by pwszLanguagesBuffer. On successful return from the function, the parameter contains the size of the retrieved language buffer.  
```  
***  


## Return value:
Returns TRUE if successful or FALSE otherwise.  
***  


## Comments:
By default, a VFP process does not have any preferred UI languages set.  
  
See also: SetProcessPreferredUILanguages   
  
***  

