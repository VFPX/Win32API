[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to make the caption of a VFP application flashing in the Windows task bar

## Before you begin:
This code sample shows how to turn user to the monitor`s screen by flashing the icon of an application in the Windows taskbar. There are several other ways of  alerting the user using various visual effects:  

* [Flashing caption of a VFP application in the Windows task bar using FlashWindowEx](sample_271.md)  
* [Shaking VFP form controls](sample_526.md)  
* [Placing On-screen Alert on top of all windows](sample_504.md)  

  
***  


## Code:
```foxpro  
DO decl

LOCAL hWindow
hWindow = GetActiveWindow()

* minimizing the main VFP window
_SCREEN.WindowState = 1

* making the window flashing on the Windows taskbar
* while staying minimized

DO WHILE _SCREEN.WindowState = 1
	* setting to the flashed state
	= FlashWindow (hWindow, 1)
	= Sleep (500) && keep for a moment

	* setting to the original state
	= FlashWindow (hWindow, 0)
	= Sleep (500) && keep for a moment
ENDDO

* clearing the flashing state
* when the WindowState returned to normal
= FlashWindow (hWindow, 0)

PROCEDURE  decl
	DECLARE Sleep IN kernel32 INTEGER dwMilliseconds
	DECLARE INTEGER GetActiveWindow IN user32

	DECLARE INTEGER FlashWindow IN user32;
		INTEGER hWnd, INTEGER bInvert  
```  
***  


## Listed functions:
[FlashWindow](../libraries/user32/FlashWindow.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[Sleep](../libraries/kernel32/Sleep.md)  

## Comment:
The FlashWindowEx provides more options. it is not supported by earlier Windows versions.  
  
***  

