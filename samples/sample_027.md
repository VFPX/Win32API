[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Listing child windows for the Windows desktop

## Code:
```foxpro  
#DEFINE GW_HWNDLAST 1
#DEFINE GW_HWNDNEXT 2
#DEFINE GW_CHILD 5
DO declare

CREATE CURSOR csResult (hWnd N(12), isvisible N(1),;
	leftpos I, toppos I, rightpos I, botpos I, wincap C(64), classname C(64))

LOCAL hDesktop, hFirstChild, hLastChild, rc, cWinCap, cWinClass,;
	nVisible, nLeft, nTop, nRight, nBottom

hDesktop = GetDesktopWindow()
hFirstChild = GetWindow(hDesktop, GW_CHILD)
hLastChild = GetWindow(hFirstChild, GW_HWNDLAST)

hCurrent = hFirstChild
DO WHILE .T.
	cWinCap = GetWinText(hCurrent)
	cWinClass= GetClsName(hCurrent)
	nVisible = IsWindowVisible(hCurrent)

	rc = Repli(Chr(0),16)
	= GetWindowRect(hCurrent, @rc)
	nLeft = buf2dword(SUBSTR(rc, 1,4))
	nTop = buf2dword(SUBSTR(rc, 5,4))
	nRight = buf2dword(SUBSTR(rc, 9,4))
	nBottom = buf2dword(SUBSTR(rc, 13,4))
	
	INSERT INTO csResult VALUES (hCurrent, nVisible,;
		nLeft, nTop, nRight, nBottom, cWinCap, cWinClass)

	IF hCurrent = hLastChild
		EXIT
	ENDIF
	hCurrent = GetWindow(hCurrent, GW_HWNDNEXT)
ENDDO
GO TOP
BROWSE NORMAL NOWAIT
* end of main

FUNCTION GetClsName(hWindow)
    LOCAL nBufsize, cBuffer
    cBuffer = Repli(Chr(0), 250)
    nBufsize = GetClassName(hWindow, @cBuffer, Len(cBuffer))
RETURN SUBSTR(cBuffer, 1, nBufsize)

FUNCTION GetWinText(hWindow)
* returns window title bar text -- Win9*/Me/XP/2000
	LOCAL cBuffer, nResult
	cBuffer = Space(250)
	nResult = GetWindowText(hWindow, @cBuffer, Len(cBuffer))
RETURN SUBSTR(cBuffer, 1, nResult)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

PROCEDURE declare
	DECLARE INTEGER GetDesktopWindow IN user32
	DECLARE INTEGER GetWindow IN user32 INTEGER hwnd, INTEGER wFlag
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect
	DECLARE INTEGER IsWindowVisible IN user32 INTEGER hWnd

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch

    DECLARE INTEGER GetClassName IN user32;
        INTEGER hWnd, STRING lpClassName, INTEGER nMaxCount  
```  
***  


## Listed functions:
[GetClassName](../libraries/user32/GetClassName.md)  
[GetDesktopWindow](../libraries/user32/GetDesktopWindow.md)  
[GetWindow](../libraries/user32/GetWindow.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
[IsWindowVisible](../libraries/user32/IsWindowVisible.md)  

## Comment:
In the resulting list you will probably find a window with a class name **Shell_TrayWnd**, which is Windows TaskBar. Using ShowWindow function it is possible to control its visibility.  
  
C# code enumerates top-level windows on the screen by a single call to the EnumWindows.  
  
***  

