[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Current directory of the application

## Code:
```foxpro  
DECLARE INTEGER SetCurrentDirectory IN kernel32;
	STRING lpPathName

DECLARE INTEGER GetCurrentDirectory IN kernel32;
	INTEGER nBufferLength, STRING @lpBuffer

LOCAL cPath
cPath = SYS(5) + SYS(2003)

= SetCurrentDirectory("c:\Program Files")
? GetCD()
? GetCD1()

= SetCurrentDirectory(cPath)
? GetCD()
? GetCD1()
* end of main

FUNCTION GetCD
RETURN SYS(5) + SYS(2003)

FUNCTION GetCD1
	LOCAL cBuffer, nBufsize
	cBuffer = SPACE(250)
	nBufsize = GetCurrentDirectory(Len(cBuffer), @cBuffer)
RETURN SUBSTR(cBuffer, 1, nBufsize)  
```  
***  


## Listed functions:
[GetCurrentDirectory](../libraries/kernel32/GetCurrentDirectory.md)  
[SetCurrentDirectory](../libraries/kernel32/SetCurrentDirectory.md)  
