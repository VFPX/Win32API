[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using FlashWindowEx to flash the taskbar button of the VFP application

## Before you begin:
This code sample shows how to turn user to the monitor's screen by flashing the icon of an application in the Windows taskbar. There are several other ways of  alerting the user using various visual effects:  

* [Flashing caption of a VFP application in the Windows task bar using FlashWindow](sample_228.md)  
* [Shaking VFP form controls](sample_526.md)  
* [Placing On-screen Alert on top of all windows](sample_504.md)  
  
***  


## Code:
```foxpro  
DO declare

#DEFINE FLASHW_STOP 0
#DEFINE FLASHW_CAPTION 1
#DEFINE FLASHW_TRAY 2
#DEFINE FLASHW_ALL BITOR(FLASHW_CAPTION, FLASHW_TRAY)
#DEFINE FLASHW_TIMER 4
#DEFINE FLASHW_TIMERNOFG 12

*| typedef struct {
*|   UINT  cbSize;      0:4
*|   HWND  hwnd;        4:4
*|   DWORD dwFlags;     8:4
*|   UINT  uCount;     12:4
*|   DWORD dwTimeout;  16:4
*| } FLASHWINFO, *PFLASHWINFO; total = 20 bytes
#DEFINE FLASHWINFO_STRU_SIZE  20

LOCAL hWindow, lcBuffer, lnFlags, lnTimes, lnInterval

hWindow = GetActiveWindow()

lnFlags = FLASHW_TRAY
lnTimes = 5
lnInterval = 0  && default cursor blink rate applied

lcBuffer = num2dword(FLASHWINFO_STRU_SIZE) +;
	num2dword(hWindow) +;
	num2dword(lnFlags) +;
	num2dword(lnTimes) +;
	num2dword(lnInterval)

= FlashWindowEx(@lcBuffer)

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

PROCEDURE declare
	DECLARE INTEGER FlashWindowEx IN user32 STRING @pfwi
	DECLARE INTEGER GetActiveWindow IN user32  
```  
***  


## Listed functions:
[FlashWindowEx](../libraries/user32/FlashWindowEx.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  

## Comment:
This is an asynchronous function, that means it returns immediately after beginning the flashing.  
  
Once the handle of a window is known, it is possible to flash the window with a caption and/or taskbar button.   
  
Another code sample shows how to [enumerate handles for the child windows](sample_261.md) of the main VFP window. Apply the FlashWindowEx to any of these windows and watch the result.  
  
* * *  
The *FlashWindowManager* class shown here once added to C# WinForm project automatically adds *Fla;shWindow* and *FlashStop* extension methods to every form in the project.  
  
With fairly small changes the *FlashWindowManager* class can be used with .NET WPF forms. 
```cpp
public static void FlashWindow(  
	this Window window,  
	FlashWinFlags flags = FlashWinFlags.FlashAll,  
	int count = int.MaxValue,  
	nt timeout = 0)  
{  
	var windowInteropHelper = new WindowInteropHelper(window);  
	FlashWindow(windowInteropHelper.Handle, flags, count, timeout);  
}
```
  
***  

