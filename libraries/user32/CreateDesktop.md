[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateDesktop
Group: [Window Station and Desktop](../../functions_group.md#Window_Station_and_Desktop)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Creates a new desktop, associates it with the current window station of the calling process, and assigns it to the calling thread.
***  


## Code examples:
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
HDESK CreateDesktop(
	LPCTSTR lpszDesktop,
	LPCTSTR lpszDevice,
	LPDEVMODE pDevmode,
	DWORD dwFlags,
	ACCESS_MASK dwDesiredAccess,
	LPSECURITY_ATTRIBUTES lpsa
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateDesktop IN user32;
	STRING  lpszDesktop,;
	INTEGER lpszDevice,;
	INTEGER pDevmode,;
	LONG    dwFlags,;
	INTEGER dwDesiredAccess,;
	INTEGER lpsa
  
```  
***  


## Parameters:
lpszDesktop 
[in] Pointer to a null-terminated string specifying the name of the desktop to be created. Desktop names are case-insensitive and may not contain backslash characters (\). 

lpszDevice 
Reserved; must be NULL. 

pDevmode 
Reserved; must be NULL. 

dwFlags 
[in] This parameter can be 0 or 1.

dwDesiredAccess 
[in] Access to the desktop.

lpsa 
[in] Pointer to a SECURITY_ATTRIBUTES structure; can be NULL.  
***  


## Return value:
If the function succeeds, the return value is a handle to the newly created desktop.  
***  


## Comments:
If the specified desktop already exists, the function succeeds and returns a handle to the existing desktop. When you are finished using the handle, call the CloseDesktop function to close it.  
  
See also: [CloseDesktop](../user32/CloseDesktop.md), [SwitchDesktop](../user32/SwitchDesktop.md).  
  
***  

