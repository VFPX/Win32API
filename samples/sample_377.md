[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Starting external program from VFP and waiting for its termination

## Before you begin:
Other code samples you might be interested in:  
* [Running external applications from VFP using WinExec](sample_002.md)  
* [Using ShellExecute for performing operations on files](sample_093.md)  
* [Running external applications from VFP using CreateProcess](sample_003.md)  
* [How to Start a Process as Another User (NT/XP/2K)](sample_426.md)  
* [Running MSDOS Shell as a child process with redirected input and output](sample_477.md)  

  
***  


## Code:
```foxpro  
DO decl

*= RunAndWait("c:\windows\notepad.exe", "")
= RunAndWait("C:\program files\Microsoft Office\Office10\excel.exe", "")
* end of main

PROCEDURE RunAndWait(lcApp, lcCmdLine)
#DEFINE START_INFO_SIZE 68
#DEFINE INFINITE  0xFFFFFFFF
#DEFINE NORMAL_PRIORITY_CLASS 0x20

	LOCAL cStartupInfo, cProcInfo, hProcess, hThread
	cStartupInfo = PADR(Chr(START_INFO_SIZE), START_INFO_SIZE, Chr(0))
	cProcInfo = Repli(Chr(0), 16)

	IF CreateProcess(lcApp+CHR(0), lcCmdLine+CHR(0),;
		0,0,1, NORMAL_PRIORITY_CLASS, 0,;
		SYS(5)+SYS(2003), @cStartupInfo, @cProcInfo) <> 0

		* process and thread handles returned in ProcInfo structure
		hProcess = buf2dword(SUBSTR(cProcInfo, 1,4))
		hThread = buf2dword(SUBSTR(cProcInfo, 5,4))

		* waiting until the termination
		= WaitForSingleObject(hProcess, INFINITE)
	    = CloseHandle(hThread)
	    = CloseHandle(hProcess)
	ELSE
		? "Error code:", GetLastError()
	ENDIF

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE decl
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER CreateProcess IN kernel32;
		STRING lpAppName, STRING lpCmdLine, INTEGER lpProcAttr,;
		INTEGER lpThrAttr, INTEGER bInhHandles, INTEGER dwCrFlags,;
		INTEGER lpEnvir, STRING lpCurDir, ;
		STRING @lpStInfo, STRING @lpProcInfo

	DECLARE INTEGER WaitForSingleObject IN kernel32;
		INTEGER hHandle, INTEGER dwMilliseconds  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateProcess](../libraries/kernel32/CreateProcess.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[WaitForSingleObject](../libraries/kernel32/WaitForSingleObject.md)  

## Comment:
  
Another option is starting external program in a different desktop. With no calls to the WaitForSingleObject made, the host VFP program stays active. Though it becomes invisible and is cut off from keyboard and mouse input.  
  
See also:  
* [How to prevent users from accessing the Windows Desktop and from switching to other applications](sample_492.md)

* * *  
C#:  This is asynchronous notification that relies on the Exited event (EnableRaisingEvents must be set to true for the Process instance). Synchronous notification relies on calling the WaitForExit method.  
  
***  

