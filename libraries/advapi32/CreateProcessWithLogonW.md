[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateProcessWithLogonW
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The CreateProcessWithLogonW function creates a new process and its primary thread. The new process then runs the specified executable file in the security context of the specified credentials (user, domain, and password). It can optionally load the user profile for the specified user.
***  


## Code examples:
[How to Start a Process as Another User (NT/XP/2K)](../../samples/sample_426.md)  

## Declaration:
```foxpro  
BOOL CreateProcessWithLogonW(
  LPCWSTR lpUsername,
  LPCWSTR lpDomain,
  LPCWSTR lpPassword,
  DWORD dwLogonFlags,
  LPCWSTR lpApplicationName,
  LPWSTR lpCommandLine,
  DWORD dwCreationFlags,
  LPVOID lpEnvironment,
  LPCWSTR lpCurrentDirectory,
  LPSTARTUPINFOW lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInfo
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateProcessWithLogonW IN Advapi32;
	STRING    lpUsername,;
	STRING    lpDomain,;
	STRING    lpPassword,;
	INTEGER   dwLogonFlags,;
	STRING    lpAppName,;
	STRING    lpCmdLine,;
	INTEGER   dwCreationFlags,;
	INTEGER   lpEnvir,;
	STRING    lpCurDir,;
	STRING  @ lpStartupInfo,;
	STRING  @ lpProcessInfo
  
```  
***  


## Parameters:
lpUsername 
[in] Pointer to a null-terminated string that specifies the name of the user. 

lpDomain 
[in] Pointer to a null-terminated string that specifies the name of the domain or server whose account database contains the lpUsername account. 

lpPassword 
[in] Pointer to a null-terminated string that specifies the clear-text password for the lpUsername account. 

dwLogonFlags 
[in] Logon option. 

lpApplicationName 
[in] Pointer to a null-terminated string that specifies the module to execute. 

lpCommandLine 
[in] Pointer to a null-terminated string that specifies the command line to execute.

dwCreationFlags 
[in] Flags that control how the process is created.

lpEnvironment 
[in] Pointer to an environment block for the new process.

lpCurrentDirectory 
[in] Pointer to a null-terminated string that specifies the current drive and directory for the new process. 

lpStartupInfo 
[in] Pointer to a STARTUPINFO structure that specifies the window station, desktop, standard handles, and appearance of the main window for the new process.

lpProcessInfo 
[out] Pointer to a PROCESS_INFORMATION structure that receives identification information for the new process, including a handle to the process.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The CreateProcessWithLogonW and CreateProcessWithTokenW functions are similar to the CreateProcessAsUser function, except that the caller does not need to call the LogonUser function to authenticate the user and get a token.  
  
***  

