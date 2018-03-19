[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating a mailslot

## Before you begin:
A *mailslot* is a mechanism for one-way interprocess communications (IPC). Applications are able to exchange data through mailslots.   

A mailslot is a *pseudofile* that resides in memory (RAM). Standard file functions, like CreateFile, ReadFile, and WriteFile, are used to access mailslots.  
  
***  


## Code:
```foxpro  
DO decl

#DEFINE INVALID_HANDLE_VALUE  -1

LOCAL hms, lcName

lcName = "\\.\mailslot\testing\my_comments"
hms = CreateMailslot (lcName, 250,500,0)

IF hms = INVALID_HANDLE_VALUE
	* 123 = ERROR_INVALID_NAME
	? "Error code:", GetLastError()
	RETURN
ENDIF

* resetting the time-out value
= SetMailslotInfo (hms, 1000)

? "Handle to the mailslot:", hms

LOCAL lnMsgSize, lnNextSize, lnMsgCount, lnTimeout
STORE 0 TO lnMsgSize, lnNextSize, lnMsgCount, lnTimeout

IF GetMailslotInfo (hms, @lnMsgSize, @lnNextSize,;
	@lnMsgCount, @lnTimeout) <> 0
	? "maximum message, bytes:", lnMsgSize
	? "next message, bytes:", lnNextSize
	? "messages waiting:", lnMsgCount
	? "time-out value, msec:", lnTimeout
ENDIF

= CloseHandle (hms)

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER

	DECLARE INTEGER CreateMailslot IN kernel32;
		STRING lpName, INTEGER nMaxMessageSize,;
		INTEGER lReadTimeout, INTEGER lpSecurityAttributes

	DECLARE INTEGER GetMailslotInfo IN kernel32;
		INTEGER hMailslot, INTEGER @lpMaxMessageSize,;
		INTEGER @lpNextSize, INTEGER @lpMessageCount,;
		INTEGER @lpReadTimeout

	DECLARE INTEGER SetMailslotInfo IN kernel32;
		INTEGER hMailslot, INTEGER lReadTimeout  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateMailslot](../libraries/kernel32/CreateMailslot.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetMailslotInfo](../libraries/kernel32/GetMailslotInfo.md)  
[SetMailslotInfo](../libraries/kernel32/SetMailslotInfo.md)  

## Comment:
When a process creates a mailslot, the name must have the following form.:  
**\\.\mailslot\**[path]name  
  
In this example the "dot" means "local machine". "testing" and "my_comments" are path and name to be picked by your application  
  
***  

