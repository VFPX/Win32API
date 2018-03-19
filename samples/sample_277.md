[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to hide your program from the Close Program dialog (Win9* only)

## Before you begin:
In numerous Tips-and-Tricks pages on the Internet for VB, Delphi, and C this little one is an old-timer. Now is the time to "port" it to the FoxPro.  
  
***  


## Code:
```foxpro  
DO decl
#DEFINE RSP_SIMPLE_SERVICE      1  && hide
#DEFINE RSP_UNREGISTER_SERVICE  0  && show

LOCAL lnProcessId
lnProcessId = GetCurrentProcessId()

* hide by registering as a service mode program
= RegisterServiceProcess (lnProcessId, RSP_SIMPLE_SERVICE)

* show
*= RegisterServiceProcess (lnProcessId, RSP_UNREGISTER_SERVICE)

PROCEDURE  decl
	DECLARE INTEGER GetCurrentProcessId IN kernel32
	DECLARE INTEGER RegisterServiceProcess IN kernel32;
		INTEGER dwProcessId, INTEGER dwType  
```  
***  


## Listed functions:
[GetCurrentProcessId](../libraries/kernel32/GetCurrentProcessId.md)  
[RegisterServiceProcess](../libraries/kernel32/RegisterServiceProcess.md)  

## Comment:
Registering your application as a service mode program removes it from the Task List in Win95/98/Me. That means it cannot be so easily aborted by an advanced user who already mastered the magic triple-key forcer.  
  
It is recommended to restore the regular mode (Simple Service) for your application before closing it, to let it free its system resources in a proper way.  
  
The RegisterServiceProcess is a documented function in KERNEL32 library. Though MSDN doesnt indicate this particular result of calling it.  
  
Here in VFP we are not much spoiled with header files as those guys with C are. Whichever external function is, it has to be declared directly in VFP code. Differently in C the RegisterServiceProcess function is not prototyped in header files. That is why they have to resort to LoadLibrary and GetProcAddress functions at first.  
  
***  

