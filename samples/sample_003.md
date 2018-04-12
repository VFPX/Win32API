[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Start an executable from VFP application by using the CreateProcess

## Before you begin:
Other code samples you might be interested in:  
* [Running external applications from VFP using WinExec](sample_002.md)  
* [Using ShellExecute for performing operations on files](sample_093.md)  
* [Running an external program from FoxPro and waiting for its termination](sample_377.md)  
* [How to Start a Process as Another User (NT/XP/2K)](sample_426.md)  
* [Running MSDOS Shell as a child process with redirected input and output](sample_477.md)  

  
***  


## Code:
```foxpro  
_run("c:\windows\notepad.exe", "c:\newfile.txt")
*_run("C:\WINDOWS\System32\mspaint.exe", "")
*_run("C:\Program Files\Microsoft Office\Office10\WINWORD.EXE", "")

* end of main

PROCEDURE _run
LPARAMETERS cApp, cCmdLine
#DEFINE START_INFO_SIZE  68
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER CreateProcess IN kernel32;
		STRING lpApplicationName, STRING lpCommandLine,;
		INTEGER lpProcessAttr, INTEGER lpThreadAttr,;
		INTEGER bInheritHandles, INTEGER dwCreationFlags,;
		INTEGER lpEnvironment, STRING lpCurrentDirectory,;
		STRING @lpStartupInfo, STRING @lpProcessInformation

	LOCAL cProcInfo, cStartInfo, nFlags, nResult, hProcess, hThread
	cProcInfo = Repli(Chr(0), 16)
	cStartInfo = PADR(Chr(START_INFO_SIZE), START_INFO_SIZE, Chr(0))
	nFlags = 0
	cApp = ALLTRIM(cApp)
	cCmdLine = " " + ALLTRIM(cCmdLine)

	nResult = CreateProcess(cApp, cCmdLine, 0,0,0,;
		nFlags, 0, SYS(5)+SYS(2003), @cStartInfo, @cProcInfo)

	IF nResult = 0
	*  2 = ERROR_FILE_NOT_FOUND
	*  3 = ERROR_PATH_NOT_FOUND
	*  5 = ERROR_ACCESS_DENIED
	* 87 = ERROR_INVALID_PARAMETER
		? "Error code:", GetLastError()
		RETURN
	ENDIF
	
	* process and thread handles returned in ProcInfo structure
	hProcess = buf2dword(SUBSTR(cProcInfo, 1,4))
	hThread = buf2dword(SUBSTR(cProcInfo, 5,4))

	IF MessageB("Click on <Yes> to terminate the process " +;
		"you have just created.   ", 32+4, "TerminateProcess API") = 6

		DECLARE INTEGER TerminateProcess IN kernel32;
			INTEGER hProcess, INTEGER uExitCode
		= TerminateProcess(hProcess, 0)
	ENDIF

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	Asc(SUBSTR(cBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(cBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(cBuffer, 4,1)) * 16777216  
```  
***  


## Listed functions:
[CreateProcess](../libraries/kernel32/CreateProcess.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[TerminateProcess](../libraries/kernel32/TerminateProcess.md)  

## Comment:
According to the Microsoft all WinExec calls are translated directly into corresponding CreateProcess calls.  
  
Microsoft Knowledge Base Article - 175986  
[Understanding CreateProcess_and Command-line Arguments](https://support.microsoft.com/en-us/help/175986/info-understanding-createprocess-and-command-line-arguments).
  
* * *  
Note overloaded Run methods in C# code.  
  
***  

