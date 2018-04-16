[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AssocQueryString
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Searches for and retrieves a file or protocol association-related string from the registry.
***  


## Code examples:
[Finding the application, icon and friendly names associated with a file name](../../samples/sample_584.md)  

## Declaration:
```foxpro  
HRESULT AssocQueryString(
  _In_       ASSOCF flags,
  _In_       ASSOCSTR str,
  _In_       LPCTSTR pszAssoc,
  _In_opt_   LPCTSTR pszExtra,
  _Out_opt_  LPTSTR pszOut,
  _Inout_    DWORD *pcchOut
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AssocQueryString IN Shlwapi;
	INTEGER queryFlags,;
	INTEGER queryString,;
	STRING pszAssoc,;
	STRING pszExtra,;
	STRING @pszOut,;
	INTEGER @pcchOut  
```  
***  


## Parameters:
flags [in]
A combination of ASSOCF values that can be used to control the search.

str [in]
The ASSOCSTR value that specifies the type of string that is to be returned.

pszAssoc [in]
A pointer to a null-terminated string that is used to determine the root key.

pszExtra [in, optional]
An optional null-terminated string with additional information about the location of the string. It is typically set to a Shell verb such as open.

pszOut [out, optional]
Pointer to a null-terminated string that, when this function returns successfully, receives the requested string.

pcchOut [in, out]
A pointer to a value that, when calling the function, is set to the number of characters in the pszOut buffer.  
***  


## Return value:
On success retuns S_OK (0), otherwise returns a standard COM error value.  
***  


## Comments:
This function is a wrapper for the IQueryAssociations interface in Shell namespace.  
  
See also: 

* [FindExecutable](../shell32/FindExecutable.md)   
* [ShellExecute](../shell32/ShellExecute.md)   
* [Displaying associated icons and descriptions for files and folders](../../samples/sample_530.md)  
  
***  

