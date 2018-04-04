[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetThreadDesktop
Group: [Window Station and Desktop](../../functions_group.md#Window_Station_and_Desktop)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetThreadDesktop function retrieves a handle to the desktop associated with a specified thread.
***  


## Code examples:
[Obtaining a handle to the desktop associated with the calling thread](../../samples/sample_239.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
HDESK GetThreadDesktop(
  DWORD dwThreadId   // thread identifier
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetThreadDesktop IN user32;
	INTEGER dwThreadId  
```  
***  


## Parameters:
dwThreadId 
[in] Handle to the thread for which to return the desktop handle. The GetCurrentThreadId and CreateProcess functions return thread identifiers.   
***  


## Return value:
If the function succeeds, the return value is a handle to the desktop associated with the specified thread.   
***  


## Comments:
Windows 95/98/Me: The system does not support multiple desktops, so GetThreadDesktop always returns the same value.  
  
***  

