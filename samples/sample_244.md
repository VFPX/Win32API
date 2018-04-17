[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Minimizing all running applications

## Before you begin:
It is almost the same if you would select the ***Minimize All Windows*** command from the Windows toolbar menu.  
  
***  


## Code:
```foxpro  
DO decl
LOCAL hWinActive, hWindow, lcWinText, hWinCount, lnWinIndex
hWinActive = GetActiveWindow()
hWindow = -1
hWinCount = 0

#DEFINE GW_HWNDFIRST  0
#DEFINE GW_HWNDLAST   1
#DEFINE GW_HWNDNEXT   2

DO WHILE hWindow <> GetWindow (hWinActive, GW_HWNDLAST)
	IF hWindow = -1
		hWindow = GetWindow(hWinActive, GW_HWNDFIRST)
	ELSE
		hWindow = GetWindow(hWindow, GW_HWNDNEXT)
	ENDIF

	IF IsWindow(hWindow) <> 0;
		And IsWindowVisible(hWindow) <> 0;
		And GetWindowTextLength(hWindow) > 0

		lcWinText = GetWinText(hWindow)

		* storing suitable window handles to an array
		IF Not "Program Manager" $ lcWinText
			hWinCount = hWinCount + 1
			DIMEN arrWin[hWinCount]
			arrWin[hWinCount] = hWindow
		ENDIF
	ENDIF
ENDDO

FOR lnWinIndex=1 TO hWinCount
	If IsIconic(arrWin[lnWinIndex]) = 0
		= CloseWindow(arrWin[lnWinIndex])
	ENDIF
ENDFOR
* end of main

FUNCTION  GetWinText(hWindow)
	LOCAL lnBufsize, lcBuffer
	lnBufsize = 1024
	lcBuffer = Repli(Chr(0), lnBufsize)
	lnBufsize = GetWindowText(hWindow, @lcBuffer, lnBufsize)
RETURN  Iif(lnBufsize=0, "", Left(lcBuffer,lnBufsize))

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow  IN user32
	DECLARE INTEGER GetWindow IN user32 INTEGER hwnd, INTEGER wFlag
	DECLARE INTEGER IsWindow IN user32 INTEGER hWnd
	DECLARE INTEGER IsWindowVisible IN user32 INTEGER hWnd
	DECLARE INTEGER GetWindowTextLength IN user32 INTEGER hWnd

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch

	DECLARE INTEGER CloseWindow IN user32 INTEGER hWnd
	DECLARE INTEGER IsIconic IN user32 INTEGER hWnd  
```  
***  


## Listed functions:
[CloseWindow](../libraries/user32/CloseWindow.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetWindow](../libraries/user32/GetWindow.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
[GetWindowTextLength](../libraries/user32/GetWindowTextLength.md)  
[IsIconic](../libraries/user32/IsIconic.md)  
[IsWindow](../libraries/user32/IsWindow.md)  
[IsWindowVisible](../libraries/user32/IsWindowVisible.md)  

## Comment:
The GetWindow is used to obtain handles to all windows siblings to the main VFP window, excluding the Program Manager window.   
  
Then the CloseWindow is applied to every handle to minimize the window.  This name is quite obscure, because the windows are in fact minimized not being closed by this function.  
  
Compare with the DestroyWindow. This name gives a clear idea of what this function really does.  
  

***  

