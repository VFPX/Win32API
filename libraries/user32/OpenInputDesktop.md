<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : OpenInputDesktop
Group: Window Station and Desktop - Library: user32    
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
```txt  
dwFlags
[in] This parameter can be 0 or 1.

fInherit
[in] If this value is TRUE, new processes inherit the handle. Otherwise, this handle is not inherited.

dwDesiredAccess
[in] Access to the desktop.  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the desktop that receives user input.  
***  


## Comments:
When you are finished using the handle, call the CloseDesktop function to close it.  
  
See also: CloseDesktop, SetProcessWindowStation, SwitchDesktop  
  
***  

