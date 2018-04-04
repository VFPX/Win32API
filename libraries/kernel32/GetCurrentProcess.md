[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCurrentProcess
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetCurrentProcess function retrieves a <Strong>pseudo</Strong> handle for the current process.
***  


## Code examples:
[Memory usage info for current VFP session (WinNT only)](../../samples/sample_172.md)  
[Retrieving the priority class for the current process](../../samples/sample_173.md)  
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  
[How to enable the SE_SHUTDOWN_NAME privilege for the application](../../samples/sample_552.md)  
[Reading and setting system access privileges for the current process](../../samples/sample_554.md)  
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[How to check whether the system is 32-bit or 64-bit](../../samples/sample_580.md)  
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
HANDLE GetCurrentProcess(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCurrentProcess;
	IN kernel32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is a <Strong>pseudo</Strong> handle to the current process.  
***  


## Comments:
A pseudo handle is a special constant that is interpreted as the current process handle. The calling process can use this handle to specify its own process whenever a process handle is required. Pseudo handles are not inherited by child processes.  
  
***  

