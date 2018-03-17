<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetCurrentProcessId
Group: Process and Thread - Library: kernel32    
***  


#### The GetCurrentProcessId function retrieves the process identifier of the calling process.
***  


## Code examples:
[GetProcessVersion points at target OS](../../samples/sample_170.md)  
[Reading and setting the priority class values for the current process and thread](../../samples/sample_218.md)  
[How to hide your program from the Close Program dialog (Win9* only)](../../samples/sample_277.md)  
[How to find when the application started](../../samples/sample_534.md)  
[Obtaining I/O counts for the current process](../../samples/sample_535.md)  

## Declaration:
```foxpro  
DWORD GetCurrentProcessId(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCurrentProcessId;
	IN kernel32  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
The return value is the process identifier of the calling process.  
***  


## Comments:
Until the process terminates, the process identifier uniquely identifies the process throughout the system.  
  
<Em>Application.ProcessId</Em> returns identical result and most likely wraps this function.  
  
***  

