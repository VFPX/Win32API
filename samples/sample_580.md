[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to check whether the system is 32-bit or 64-bit

## Before you begin:
The IsWow64Process function determines whether the specified process is running under WOW64.   
  
***  


## Code:
```foxpro  
DO declare

LOCAL nHandle, lWow64Process

nHandle = GetCurrentProcess()
lWow64Process = 0

IsWow64Process(nHandle, @lWow64Process)

CloseHandle(nHandle)

? IIF(lWow64Process = 0, "32-bit", "64-bit")
* end of main

PROCEDURE declare
	DECLARE INTEGER GetCurrentProcess IN kernel32
	
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject	
	
	DECLARE INTEGER IsWow64Process IN kernel32;
		INTEGER hProcess, INTEGER @Wow64Process  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetCurrentProcess](../libraries/kernel32/GetCurrentProcess.md)  
[IsWow64Process](../libraries/kernel32/IsWow64Process.md)  

## Comment:
Note that the minimum supported client:is Windows XP with SP2.  
  
By calling API functions LoadLibrary and GetProcAddress it is possible to determine whether the IsWow64Process is included in the present Kernel32.dll library.  
  
In .NET Framework 4 and on, use <a href="https://msdn.microsoft.com/en-us/library/system.environment.is64bitoperatingsystem(v=vs.100).aspx">Environment.Is64BitOperatingSystem</a>.  
  
***  

