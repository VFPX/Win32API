[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateProcessAsUser
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The CreateProcessAsUser function creates a new process and its primary thread. The new process then runs the specified executable file. The CreateProcessAsUser function is similar to the CreateProcess function, except that the new process runs in the security context of the user represented by the hToken parameter.
***  


## Code examples:
[How to Start a Process as Another User (NT/XP/2K)](../../samples/sample_426.md)  

## Declaration:
```foxpro  
BOOL CreateProcessAsUser(
  HANDLE hToken,
  LPCTSTR lpApplicationName,
  LPTSTR lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL bInheritHandles,
  DWORD dwCreationFlags,
  LPVOID lpEnvironment,
  LPCTSTR lpCurrentDirectory,
  LPSTARTUPINFO lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateProcessAsUser IN advapi32;
	INTEGER hToken,;
	STRING    lpApplicationName,;
	STRING    lpCommandLine,;
	INTEGER   lpProcessAttributes,;
	INTEGER   lpThreadAttributes,;
	INTEGER   bInheritHandles,;
	INTEGER   dwCreationFlags,;
	INTEGER   lpEnvironment,;
	STRING    lpCurrentDirectory,;
	STRING  @ lpStartupInfo,;
	STRING  @ lpProcessInformation
  
```  
***  


## Parameters:
hToken 
[in] Handle to a primary token that represents a user. The handle must have the TOKEN_QUERY, TOKEN_DUPLICATE, and TOKEN_ASSIGN_PRIMARY access rights.

lpApplicationName 
[in] Pointer to a null-terminated string that specifies the module to execute.

lpCommandLine 
[in] Pointer to a null-terminated string that specifies the command line to execute.

lpProcessAttributes 
[in] Pointer to a SECURITY_ATTRIBUTES structure that specifies a security descriptor for the new process and determines whether child processes can inherit the returned handle.

lpThreadAttributes 
[in] Pointer to a SECURITY_ATTRIBUTES structure that specifies a security descriptor for the new process and determines whether child processes can inherit the returned handle.

bInheritHandles 
[in] If this parameter is TRUE, each inheritable handle in the calling process is inherited by the new process.

dwCreationFlags 
[in] Flags that control the priority class and the creation of the process.

lpEnvironment 
[in] Pointer to an environment block for the new process.

lpCurrentDirectory 
[in] Pointer to a null-terminated string that specifies the current drive and directory for the new process.

lpStartupInfo 
[in] Pointer to a STARTUPINFO structure that specifies the window station, desktop, standard handles, and appearance of the main window for the new process. 

lpProcessInformation 
[out] Pointer to a PROCESS_INFORMATION structure that receives identification information about the new process.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The CreateProcessWithLogonW and CreateProcessWithTokenW functions are similar to CreateProcessAsUser, except that the caller does not need to call the LogonUser function to authenticate the user and get a token.  
  
This function is also similar to the SHCreateProcessAsUserW function.  
  
Handles in PROCESS_INFORMATION must be closed with CloseHandle when they are no longer needed.  
  
***  

