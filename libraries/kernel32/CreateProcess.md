[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateProcess
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The CreateProcess function creates a new process and its primary thread. The new process runs the specified executable file.

The CreateProcess function is used to run a new program. The WinExec and LoadModule functions are still available, but they are implemented as calls to CreateProcess
***  


## Code examples:
[Start an executable from VFP application by using the CreateProcess](../../samples/sample_003.md)  
[Starting external program from VFP and waiting for its termination](../../samples/sample_377.md)  
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  
[How to make application automatically close all documents it opened](../../samples/sample_491.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  

## Declaration:
```foxpro  
BOOL CreateProcess(
  LPCTSTR lpApplicationName,           // name of executable module
  LPTSTR lpCommandLine,                // command line string
  LPSECURITY_ATTRIBUTES lpProcessAttr, // SD
  LPSECURITY_ATTRIBUTES lpThreadAttr,  // SD
  BOOL bInheritHandles,                // handle inheritance option
  DWORD dwCreationFlags,               // creation flags
  LPVOID lpEnvironment,                // new environment block
  LPCTSTR lpCurrentDirectory,          // current directory name
  LPSTARTUPINFO lpStartupInfo,         // startup information
  LPPROCESS_INFORMATION lpProcessInfo  // process information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateProcess IN kernel32;
	STRING   lpApplicationName,;
	STRING   lpCommandLine,;
	INTEGER  lpProcessAttributes,;
	INTEGER  lpThreadAttributes,;
	INTEGER  bInheritHandles,;
	INTEGER  dwCreationFlags,;
	INTEGER  lpEnvironment,;
	STRING   lpCurrentDirectory,;
	STRING   lpStartupInfo,;
	STRING @ lpProcessInformation
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.
If the function fails, the return value is zero. To get extended error information, call 
  
***  


## Comments:
See also: [ShellExecute](../shell32/ShellExecute.md), [WinExec](../kernel32/WinExec.md).  
  
***  

