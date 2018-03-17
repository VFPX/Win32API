<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CreateWaitableTimer
Group: Synchronization - Library: kernel32    
***  


#### Creates or opens a waitable timer object.
***  


## Code examples:
[How to suspend or hibernate your system](../../samples/sample_395.md)  

## Declaration:
```foxpro  
HANDLE WINAPI CreateWaitableTimer(
	LPSECURITY_ATTRIBUTES lpTimerAttributes,
	BOOL bManualReset,
	LPCTSTR lpTimerName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateWaitableTimer IN kernel32;
	INTEGER lpTimerAttrib,;
	INTEGER bManualReset,;
	STRING lpTimerName  
```  
***  


## Parameters:
```txt  
lpTimerAttributes
[in] A pointer to a SECURITY_ATTRIBUTES structure that specifies a security descriptor for the new timer object and determines whether child processes can inherit the returned handle.

bManualReset
[in] If this parameter is TRUE, the timer is a manual-reset notification timer. Otherwise, the timer is a synchronization timer.

lpTimerName
[in] The name of the timer object. The name is limited to MAX_PATH characters. Name comparison is case sensitive. If lpTimerName is NULL, the timer object is created without a name.
  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the timer object.  
***  


## Comments:
Use the CloseHandle function to close the handle. The system closes the handle automatically when the process terminates. The timer object is destroyed when its last handle has been closed.  
  
***  

