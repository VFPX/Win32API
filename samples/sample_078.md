[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Comparing dimensions of the VFP main window with _SCREEN properties

## Code:
```foxpro  
DO decl

* displays dimensions for the objects
DO _winRect      && main VFP window
DO _clientRect   && client part of the main VFP window
DO _screenRect   && _screen object

PROCEDURE _screenRect
	?
	? "*** _SCREEN dimensions"
	? "    left:   " + STR(_screen.left,   6)
	? "    top:    " + STR(_screen.top,    6)
	? "    width:  " + STR(_screen.width,  6)
	? "    height: " + STR(_screen.height, 6)

PROCEDURE _winRect
	lpRect = REPLI (Chr(0), 16)
	= GetWindowRect (GetActiveWindow(), @lpRect)
	
	lnWinLeft   = buf2dword(SUBSTR(lpRect,  1,4))
	lnWinTop    = buf2dword(SUBSTR(lpRect,  5,4))
	lnWinRight  = buf2dword(SUBSTR(lpRect,  9,4))
	lnWinBottom = buf2dword(SUBSTR(lpRect, 13,4))
	lnWinWidth  = lnWinRight - lnWinLeft + 1
	lnWinHeight = lnWinBottom - lnWinTop + 1

	? "*** Main VFP window rectangle"
	? "    left:   " + STR(lnWinLeft,   6)
	? "    top:    " + STR(lnWinTop,    6)
	? "    right:  " + STR(lnWinRight,  6)
	? "    bottom: " + STR(lnWinBottom, 6)
	? "    width:  " + STR(lnWinWidth,  6)
	? "    height: " + STR(lnWinHeight, 6)

PROCEDURE _clientRect
	lpRect = REPLI (Chr(0), 16)
	= GetClientRect (GetActiveWindow(), @lpRect)
	
	?
	lnWinLeft   = buf2dword(SUBSTR(lpRect,  1,4))
	lnWinTop    = buf2dword(SUBSTR(lpRect,  5,4))
	lnWinRight  = buf2dword(SUBSTR(lpRect,  9,4))
	lnWinBottom = buf2dword(SUBSTR(lpRect, 13,4))
	lnWinWidth  = lnWinRight - lnWinLeft + 1
	lnWinHeight = lnWinBottom - lnWinTop + 1

	? "*** Main VFP client window rectangle"
	? "    left:   " + STR(lnWinLeft,   6)
	? "    top:    " + STR(lnWinTop,    6)
	? "    right:  " + STR(lnWinRight,  6)
	? "    bottom: " + STR(lnWinBottom, 6)
	? "    width:  " + STR(lnWinWidth,  6)
	? "    height: " + STR(lnWinHeight, 6)

PROCEDURE decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect
	DECLARE INTEGER GetClientRect IN user32 INTEGER hwnd, STRING @lpRect

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetClientRect](../libraries/user32/GetClientRect.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  

## Comment:
_SCREEN Width and Height are affected by the state of:  
* VFP System Menu (try RELEASE MENU _msysmenu)  
* VFP status bar  (try SET STATUS BAR ON/OFF)  
* VFP toolbar: where it is docked, how many controls it contains  
* VFP Command Window: whether it is dockable or notChange the state of these objects, and check how it affects the output of this code.  
  
***  

