[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting command-line string to a set of Unicode argument strings

## Code:
```foxpro  
DO declare

LOCAL lnCmdlinePtr, lnArrayPtr, lnParamCnt
lnCmdlinePtr = GetCommandLine()
lnParamCnt = 0

lnArrayPtr = CommandLineToArgvW( lnCmdlinePtr, @lnParamCnt )
	
IF lnArrayPtr = 0 Or lnParamCnt = 0
	? "Error code returned:", GetLastError()
	RETURN
ENDIF
	
LOCAL lnArraySize, lcBuffer
lnArraySize = GlobalSize(lnArrayPtr)
lcBuffer = Repli(Chr(0), lnArraySize)
	
= CopyMemory (@lcBuffer, lnArrayPtr, lnArraySize)
= GlobalFree (lnArrayPtr)
	
* the first DWORD (4 bytes) stores a pointer to data
* a contiguous memory block is assumed
lcBuffer = SUBSTR(lcBuffer, 5)
? lcBuffer
	
PROCEDURE  declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetCommandLine IN kernel32
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

	DECLARE INTEGER CommandLineToArgvW IN shell32;
		INTEGER lpCmdLine, INTEGER @pNumArgs

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Dest, INTEGER Source, INTEGER nLength  
```  
***  


## Listed functions:
[CommandLineToArgvW](../libraries/shell32/CommandLineToArgvW.md)  
[CopyMemory](../libraries/kernel32/CopyMemory.md)  
[GetCommandLine](../libraries/kernel32/GetCommandLine.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
