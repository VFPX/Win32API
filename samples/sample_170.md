[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GetProcessVersion points at target OS

## Code:
```foxpro  
DECLARE INTEGER GetCurrentProcessId IN kernel32

DECLARE INTEGER GetProcessVersion IN kernel32;
	INTEGER ProcessId

#DEFINE _FFFF 0x0000ffff
#DEFINE FFFF_  0xffff0000

	LOCAL lnProcId, lnProcVer
	
	* can be replaced with 0, specifying the current process
	lnProcId = GetCurrentProcessId()

	lnProcVer = GetProcessVersion (lnProcId)
	
	? "Process Id:", lnProcId
	? "Process Version:", lnProcVer  
```  
***  


## Listed functions:
[GetCurrentProcessId](../libraries/kernel32/GetCurrentProcessId.md)  
[GetProcessVersion](../libraries/kernel32/GetProcessVersion.md)  

## Comment:
Under VFP3 this function returns value 196618 (decimal), that means 0x0003000a -- major version 3, and minor version 10.  
VFP6 returns 262144 -- major version 4, and minor version 0. So does Delphi 5.  
  
From that I could suppose that VFP was designed primarily for Windows 3.1x, most evidently. Nevertheless I don"t insist on this idea, just because VB6 -- the dearest child of Bill G. -- returns 0 (z-z-z-zero!).  
  
That is why the only conclusion I come to is that Microsoft does not care much of this function.   
  
***  

