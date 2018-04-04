[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenEvent
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The OpenEvent function opens an existing named event object.
***  


## Code examples:
[Using an Event Object. Part B: running an application responding to events](../../samples/sample_149.md)  

## Declaration:
```foxpro  
HANDLE OpenEvent(
  DWORD dwDesiredAccess,  // access
  BOOL bInheritHandle,    // inheritance option
  LPCTSTR lpName          // object name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenEvent IN kernel32;
	INTEGER dwDesiredAccess,;
	INTEGER bInheritHandle,;
	STRING  lpName  
```  
***  


## Parameters:
dwDesiredAccess 
[in] Specifies the requested access to the event object.

bInheritHandle 
[in] Specifies whether the returned handle is inheritable. 

lpName 
[in] Pointer to a null-terminated string that names the event to be opened. Name comparisons are case sensitive.  
***  


## Return value:
If the function succeeds, the return value is a handle to the event object.  
***  

