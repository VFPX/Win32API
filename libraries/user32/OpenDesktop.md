[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenDesktop
Group: [Window Station and Desktop](../../functions_group.md#Window_Station_and_Desktop)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The OpenDesktop function opens the specified desktop object.
***  


## Code examples:
[How to start the screen saver and how to find whether the screen saver is active](../../samples/sample_196.md)  

## Declaration:
```foxpro  
HDESK OpenDesktop(
  LPTSTR lpszDesktop,
  DWORD dwFlags,
  BOOL fInherit,
  ACCESS_MASK dwDesiredAccess
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenDesktop IN user32;
	STRING  lpszDesktop,;
	LONG    dwFlags,;
	INTEGER fInherit,;
	INTEGER dwDesiredAccess
  
```  
***  


## Parameters:
lpszDesktop 
[in] Pointer to null-terminated string specifying the name of the desktop to be opened. 
dwFlags 
[in] This parameter can be zero or the following value.

fInherit 
[in] If this value is TRUE, new processes inherit the handle. Otherwise, this handle is not inherited. 

dwDesiredAccess 
[in] Access to the desktop.  
***  


## Return value:
If the function succeeds, the return value is a handle to the opened desktop.  
***  


## Comments:
Desktop names are case-insensitive. This desktop must belong to the current window station.  
  
When you are finished using the handle, call the CloseDesktop function to close it.  
  
***  

