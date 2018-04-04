[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeCreateProcess
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function is used to run a new program. It creates a new process and its primary thread. The new process executes the specified executable file.
***  


## Code examples:
[PocketPC: custom RAPI class for executing routines on remote Windows CE device](../../samples/sample_466.md)  

## Declaration:
```foxpro  
BOOL CeCreateProcess(
  LPCWSTR lpApplicationName,
  LPCWSTR lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL bInheritHandles,
  DWORD dwCreationFlags,
  LPVOID lpEnvironment,
  LPWSTR lpCurrentDirectory,
  LPSTARTUPINFO lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeCreateProcess IN rapi;
	STRING   lpAppName,;
	STRING   lpCmdLine,;
	INTEGER  lpProcAttr,;
	INTEGER  lpThreadAttr,;
	INTEGER  bInheritHandles,;
	INTEGER  dwCreationFlags,;
	INTEGER  lpEnvironment,;
	INTEGER  lpCurrDir,;
	INTEGER  lpStartupInfo,;
	STRING @ lpProcInfo  
```  
***  


## Parameters:
lpApplicationName 
[in] Long pointer to a null-terminated string that specifies the module to execute.

lpCommandLine 
[in] Long pointer to a null-terminated string that specifies the command line to execute. 

lpProcessAttributes 
[in] Not supported; set to NULL. 

lpThreadAttributes 
[in] Not supported; set to NULL. 

bInheritHandles 
[in] Not supported; set to FALSE. 

dwCreationFlags 
[in] Specifies additional flags that control the priority class and the creation of the process.

lpEnvironment 
[in] Not supported; set to NULL. 

lpCurrentDirectory 
[in] Not supported; set to NULL. 

lpStartupInfo 
[in] Not supported; set to NULL. 

lpProcessInformation 
[out] Long pointer to a PROCESS_INFORMATION structure that receives identification information about the new process.  
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
To determine if a function failed because of RAPI errors, call CeRapiGetError. To determine if a function failed because of non-RAPI errors, call CeGetLastError.  
  
***  

