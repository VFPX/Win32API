[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Finding the path to the VFP executable running

## Code:
```foxpro  
DECLARE INTEGER GetModuleHandle IN kernel32;
	INTEGER lpModuleName

DECLARE INTEGER GetModuleFileName IN kernel32;
	INTEGER  hModule,;
	STRING @ lpFilename,;
	INTEGER  nSize

hModule = GetModuleHandle(0)
lpFilename = SPACE(250)

lnLen = GetModuleFileName (hModule, @lpFilename, Len(lpFilename))
? Left (lpFilename, lnLen)  
```  
***  


## Listed functions:
[GetModuleFileName](../libraries/kernel32/GetModuleFileName.md)  
[GetModuleHandle](../libraries/kernel32/GetModuleHandle.md)  

## Comment:
Depending on OS, VFP version running, and differently for run-time and command window mode you may get various results:  
  
c:\vfp\vfp.exe  
c:\winnt\system32\vfp300.esl  
c:\Program Files\Microsoft Visual Studio\VFP98\VFP6.Exe  
...  
  
***  
```foxpro
? _vfp.servername
```
  
  
  
  
***  

