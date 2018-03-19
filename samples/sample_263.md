[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining some properties for the Windows desktop using the GetWindowPlacement function

## Before you begin:
One more way to obtain display resolution for your system.  
  
***  


## Code:
```foxpro  
DO decl

*| typedef struct _WINDOWPLACEMENT {
*|     UINT  length;              0:4
*|     UINT  flags;               4:4
*|     UINT  showCmd;             8:4
*|     POINT ptMinPosition;      12:8
*|     POINT ptMaxPosition;      20:8
*|     RECT  rcNormalPosition;   28:16
*| } WINDOWPLACEMENT; total bytes = 44 bytes
#DEFINE WINDOWPLACEMENT_SIZE  44

LOCAL hWindow, lcBuffer, lnShowCmd
hWindow = GetDesktopWindow()

lcBuffer = Chr(WINDOWPLACEMENT_SIZE) +;
	Repli(Chr(0), WINDOWPLACEMENT_SIZE-1)

= GetWindowPlacement (hWindow, @lcBuffer)
? "Minimized window flags:", buf2dword(SUBSTR(lcBuffer, 5,4))

* for the Windows Desktop it is usually SW_SHOWNORMAL = 1
? "Window show state:", buf2dword(SUBSTR(lcBuffer, 9,4))

? "Minimized position upper-left:", buf2dword(SUBSTR(lcBuffer, 13,4)),;
	buf2dword(SUBSTR(lcBuffer, 17,4))

? "Maximized position upper-left:", buf2dword(SUBSTR(lcBuffer, 21,4)),;
	buf2dword(SUBSTR(lcBuffer, 25,4))

* one more way to obtain display resolution for your system
? "Restored position rectangle:", buf2dword(SUBSTR(lcBuffer, 29,4)),;
	buf2dword(SUBSTR(lcBuffer, 33,4)), buf2dword(SUBSTR(lcBuffer, 37,4)),;
	buf2dword(SUBSTR(lcBuffer, 41,4))

FUNCTION  buf2dword (lcBuffer)
#DEFINE MAX_DWORD 0xffffffff
#DEFINE MAX_LONG 0x7FFFFFFF
	LOCAL lnResult
	lnResult = Asc(SUBSTR(lcBuffer, 1,1)) + ;
		Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
		Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
		Asc(SUBSTR(lcBuffer, 4,1)) * 16777216
RETURN Iif(lnResult>MAX_LONG, lnResult-MAX_DWORD, lnResult)

PROCEDURE decl
	DECLARE INTEGER GetDesktopWindow IN user32

	DECLARE INTEGER GetWindowPlacement IN user32;
		INTEGER hWnd, STRING @lpwndpl  
```  
***  


## Listed functions:
[GetDesktopWindow](../libraries/user32/GetDesktopWindow.md)  
[GetWindowPlacement](../libraries/user32/GetWindowPlacement.md)  
