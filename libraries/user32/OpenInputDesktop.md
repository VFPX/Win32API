[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenInputDesktop
Group: [Window Station and Desktop](../../functions_group.md#Window_Station_and_Desktop)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Opens the desktop that receives user input.

***  


## Code examples:
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
HDESK OpenInputDesktop(
	DWORD dwFlags,
	BOOL fInherit,
	ACCESS_MASK dwDesiredAccess
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenInputDesktop IN user32;
	LONG    dwFlags,;
	INTEGER fInherit,;
	INTEGER dwDesiredAccess
  
```  
***  


## Parameters:
dwFlags 
[in] This parameter can be 0 or 1.

fInherit 
[in] If this value is TRUE, new processes inherit the handle. Otherwise, this handle is not inherited. 

dwDesiredAccess 
[in] Access to the desktop.  
***  


## Return value:
If the function succeeds, the return value is a handle to the desktop that receives user input.  
***  


## Comments:
When you are finished using the handle, call the CloseDesktop function to close it.  
  
See also: [CloseDesktop](../user32/CloseDesktop.md), [SetProcessWindowStation](..//SetProcessWindowStation.md), [SwitchDesktop](../user32/SwitchDesktop.md).  
  
***  

