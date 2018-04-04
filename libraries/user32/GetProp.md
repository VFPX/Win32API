[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProp
Group: [Window Property](../../functions_group.md#Window_Property)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves a data handle from the property list of the specified window. The character string identifies the handle to be retrieved. The string and handle must have been added to the property list by a previous call to the SetProp function.
***  


## Code examples:
[How to write and read Window Properties for the specified window](../../samples/sample_205.md)  

## Declaration:
```foxpro  
HANDLE GetProp(
  HWND hWnd,         // handle to window
  LPCTSTR lpString   // atom or string
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProp IN user32;
	INTEGER hWnd,;
	STRING  lpStr  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window whose property list is to be searched. 

lpString 
[in] Pointer to a null-terminated character string or contains an atom that identifies a string.   
***  


## Return value:
If the property list contains the string, the return value is the associated data handle. Otherwise, the return value is NULL.  
***  


## Comments:
Windows 7:   
If a window owns an explicit Application User Model ID (<a href="http://msdn.microsoft.com/en-us/library/dd391569(VS.85).aspx">AppUserModelID</a>), calling the GetProp for this window with property name "{9F4C2855-9F79-4B39-A8D0-E1D42DE1D5F3} 5" returns valid data handle to IPropertyStore (?).  
  
***  

