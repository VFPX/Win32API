[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving a handle to DLL and address of an exported function in it

## Code:
```foxpro  
DO declare

LOCAL lcModule, lcProc, lcSysDir, hModule, lnAddr
lcModule = "kernel32.dll"
lcProc = "GetTickCount"
lcSysDir = GetSysDir()

hModule = GetModuleHandle(lcSysDir + CHR(92) + lcModule)
lnAddr = GetProcAddress(hModule, lcProc)

IF lnAddr = 0
	? "Error code:", GetLastError()
ELSE
	? "Address of " + lcProc + " in " + lcModule + ":",;
		"0x"+int2hex(lnAddr)
ENDIF

FUNCTION GetSysDir
	LOCAL lpBuffer, lnSize
	lpBuffer = SPACE (250)
	lnSize = GetSystemDirectory (@lpBuffer, Len(lpBuffer))
RETURN LEFT(lpBuffer, lnSize)

FUNCTION int2hex(num)
	LOCAL lnResult, lcResult
	lcResult = SPACE(20)
	lnResult = wnsprintf(@lcResult, 20, "%x", num)
RETURN LEFT(lcResult, lnResult)

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetModuleHandle IN kernel32 STRING lpModule

	DECLARE INTEGER GetProcAddress IN kernel32;
		INTEGER hModule, STRING lpPrcName
	
	DECLARE INTEGER GetSystemDirectory IN kernel32;
		STRING @lpBuffer, INTEGER nSize

	DECLARE INTEGER wnsprintf IN Shlwapi;
		STRING @lpOut, INTEGER cchLimitIn,;
		STRING pszFmt, INTEGER  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetModuleHandle](../libraries/kernel32/GetModuleHandle.md)  
[GetProcAddress](../libraries/kernel32/GetProcAddress.md)  
[GetSystemDirectory](../libraries/kernel32/GetSystemDirectory.md)  
[wnsprintf](../libraries/shlwapi/wnsprintf.md)  
