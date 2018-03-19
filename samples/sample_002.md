[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Starting an external application in VFP using WinExec

## Before you begin:
This code displays an ASCII file in maximized Notepad window. The file C:\newfile.txt is created if it does not exist.  

Other code samples you might be interested in:  
* [Using ShellExecute for performing operations on files](sample_093.md)  
* [Running external applications from VFP using CreateProcess](sample_003.md)  
* [Running an external program from FoxPro and waiting for its termination](sample_377.md)  
* [How to Start a Process as Another User (NT/XP/2K)](sample_426.md)  
* [Running MSDOS Shell as a child process with redirected input and output](sample_477.md)  

  
***  


## Code:
```foxpro  
#DEFINE SW_HIDE 0
#DEFINE SW_SHOWNORMAL 1
#DEFINE SW_SHOWMINIMIZED 2
#DEFINE SW_SHOWMAXIMIZED 3
#DEFINE SW_SHOWNOACTIVATE 4
#DEFINE SW_SHOW 5
#DEFINE SW_MINIMIZE 6
#DEFINE SW_SHOWMINNOACTIVE 7
#DEFINE SW_SHOWNA 8
#DEFINE SW_RESTORE 9
#DEFINE SW_SHOWDEFAULT 10

DECLARE INTEGER WinExec IN kernel32;
	STRING lpCmdLine, INTEGER nCmdShow

LOCAL cCmdLine, nResult

cCmdLine = ["notepad" "c:\newfile.txt"]
*!*	cCmdLine = "C:\Program Files\Microsoft Office\Office10\WINWORD.EXE"

nResult = WinExec(cCmdLine, SW_SHOWDEFAULT)

IF nResult <= 31
	= MESSAGEBOX("WinExec failed with an error: " +;
		LTRIM(STR(nResult)) + "     ", 48)
ENDIF  
```  
***  


## Listed functions:
[WinExec](../libraries/kernel32/WinExec.md)  

## Comment:
Running external applications through the WinExec call you bypass FOXRUN.PIF which makes the whole thing more efficient. According to the Microsoft: all WinExec calls are translated directly into corresponding CreateProcess calls.  
  
***  

