[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetThreadExecutionState
Group: [Power Management](../../functions_group.md#Power_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Enables applications to inform the system that it is in use, thereby preventing the system from entering the sleeping power state or turning off the display while the application is running.
***  


## Code examples:
[How to suspend or hibernate your system](../../samples/sample_395.md)  

## Declaration:
```foxpro  
EXECUTION_STATE SetThreadExecutionState(
	EXECUTION_STATE esFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetThreadExecutionState IN kernel32;
	INTEGER esFlags  
```  
***  


## Parameters:
esFlags 
[in] Execution requirements for the thread.  
***  


## Return value:
If the function succeeds, the return value is the previous thread execution state.
If the function fails, the return value is NULL.
  
***  


## Comments:
To run properly on a power-managed computer, applications such as fax servers, answering machines, backup agents, and network management applications must use ES_SYSTEM_REQUIRED | ES_CONTINUOUS when they process events.   
  
Multimedia applications, such as video players and presentation applications, must use ES_DISPLAY_REQUIRED when they display video for long periods of time without user input. Applications such as word processors, spreadsheets, browsers, and games do not need to call SetThreadExecutionState.  
  
***  

