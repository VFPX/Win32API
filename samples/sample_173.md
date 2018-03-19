[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the priority class for the current process

## Code:
```foxpro  
DECLARE INTEGER GetCurrentProcess IN kernel32

DECLARE INTEGER GetPriorityClass IN kernel32;
	INTEGER hProcess

#DEFINE NORMAL_PRIORITY_CLASS     32
#DEFINE IDLE_PRIORITY_CLASS       64
#DEFINE HIGH_PRIORITY_CLASS      128
#DEFINE REALTIME_PRIORITY_CLASS  256

	lnPriority = GetPriorityClass(GetCurrentProcess())

	? "Priority class: "
	DO CASE
	CASE lnPriority = NORMAL_PRIORITY_CLASS
		?? "Normal"
	CASE lnPriority = IDLE_PRIORITY_CLASS
		?? "Idle"
	CASE lnPriority = HIGH_PRIORITY_CLASS
		?? "High"
	CASE lnPriority = REALTIME_PRIORITY_CLASS
		?? "Real Time"
	OTHER
		?? "Unknown"
	ENDCASE  
```  
***  


## Listed functions:
[GetCurrentProcess](../libraries/kernel32/GetCurrentProcess.md)  
[GetPriorityClass](../libraries/kernel32/GetPriorityClass.md)  
