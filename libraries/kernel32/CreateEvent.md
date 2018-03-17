<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CreateEvent
Group: Synchronization - Library: kernel32    
***  


#### The CreateEvent function creates or opens a named or unnamed event object.
***  


## Code examples:
[Using an Event Object. Part A: running an application that creates an Event object](../../samples/sample_148.md)  

## Declaration:
```foxpro  
HANDLE CreateEvent(
  LPSECURITY_ATTRIBUTES lpEventAttributes, // SD
  BOOL bManualReset,                       // reset type
  BOOL bInitialState,                      // initial state
  LPCTSTR lpName                           // object name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateEvent IN kernel32;
	INTEGER lpEventAttributes,;
	INTEGER bManualReset,;
	INTEGER bInitialState,;
	STRING  lpName  
```  
***  


## Parameters:
```txt  
lpEventAttributes
[in] Pointer to a structure that determines whether the returned handle can be inherited by child processes.

bManualReset
[in] Specifies whether a manual-reset or auto-reset event object is created.

bInitialState
[in] Specifies the initial state of the event object.

lpName
[in] Pointer to a null-terminated string specifying the name of the event object.  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the event object.  
***  

