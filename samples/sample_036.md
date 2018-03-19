[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Closing Windows

## Before you begin:
Similar examples:   
* [How to initiate System shutdown (WinNT only)](sample_122.md)  
* [Restarting Windows](sample_361.md)  
* [Enabling the SE_SHUTDOWN_NAME privilege for the application](sample_552.md)  
  
***  


## Code:
```foxpro  
#DEFINE EWX_LOGOFF 0
#DEFINE EWX_SHUTDOWN 1
#DEFINE EWX_REBOOT 2
#DEFINE EWX_FORCE 4
#DEFINE EWX_POWEROFF 8
#DEFINE EWX_FORCEIFHUNG 16

DECLARE INTEGER GetLastError IN kernel32

DECLARE INTEGER ExitWindows IN user32;
	INTEGER dwReserved, INTEGER uReturnCode

DECLARE INTEGER ExitWindowsEx IN user32;
	INTEGER uFlags, INTEGER dwReserved

* logoff -- change user
* = ExitWindowsEx(EWX_LOGOFF, 0)

* reboot
nResult = ExitWindowsEx(EWX_REBOOT, 0)

IF nResult=0
* 1314=ERROR_PRIVILEGE_NOT_HELD
	? "ExitWindowsEx call failed:", GetLastError()
ENDIF  
```  
***  


## Listed functions:
[ExitWindows](../libraries/user32/ExitWindows.md)  
[ExitWindowsEx](../libraries/user32/ExitWindowsEx.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
To shut down the local computer, the calling thread must have the SE_SHUTDOWN_NAME privilege.  
  
***  

