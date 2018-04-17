[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the SystemParametersInfo function

## Before you begin:
Use the SystemParametersInfo function to retrieve and set various system parameters: desktop, isons, mouse, screen saver, windows parts sizing etc.  
  
***  


## Code:
```foxpro  
*	DO p1  && work area
	DO p2  && retrieving screen saver parameters
*	DO p3  && setting a wallpaper

PROCEDURE  p3
* setting a wallpaper
#DEFINE SPI_SETDESKWALLPAPER    20
#DEFINE SPIF_SENDWININICHANGE 1
#DEFINE SPIF_UPDATEINIFILE 2

	DECLARE INTEGER SystemParametersInfo IN user32;
		INTEGER uiAction, INTEGER uiParam,;
		STRING @pvParam, INTEGER fWinIni

	LOCAL lcWallpaper, nFlag
	nFlag = SPIF_UPDATEINIFILE + SPIF_SENDWININICHANGE
	lcWallpaper = "c:\windows\pinstripe.bmp" && a valid image file
*	lcWallpaper = ""  && removes the wallpaper

	= SystemParametersInfo (SPI_SETDESKWALLPAPER,;
		0, @lcWallpaper, nFlag)

PROCEDURE  p2
* retrieving screen saver parameters
#DEFINE SPI_GETSCREENSAVEACTIVE     16
#DEFINE SPI_GETSCREENSAVERRUNNING  114
#DEFINE SPI_GETSCREENSAVETIMEOUT    14

	DECLARE INTEGER SystemParametersInfo IN user32;
		INTEGER uiAction, INTEGER uiParam,;
		INTEGER @pvParam, INTEGER fWinIni
	
	LOCAL lnBuffer
	lnBuffer = 0

	= SystemParametersInfo(SPI_GETSCREENSAVEACTIVE, 0, @lnBuffer, 0)
	? "Screen saving is enabled:", lnBuffer

	* Windows 98/Me, Windows 2000/XP
	= SystemParametersInfo(SPI_GETSCREENSAVERRUNNING, 0, @lnBuffer, 0)
	? "Screen saving is currently running:", lnBuffer

	= SystemParametersInfo(SPI_GETSCREENSAVETIMEOUT, 0, @lnBuffer, 0)
	? "Screen saver time-out value, seconds:", lnBuffer

PROCEDURE  p1
* retrieving the size of the work area on the primary display monitor.
* The work area is the portion of the screen not obscured
* by the system taskbar or by application desktop toolbars.
#DEFINE SPI_GETWORKAREA    48

	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), 16)

	DECLARE INTEGER SystemParametersInfo IN user32;
		INTEGER uiAction, INTEGER uiParam,;
		STRING @pvParam, INTEGER fWinIni

	= SystemParametersInfo(SPI_GETWORKAREA, 0, @lcBuffer, 0)

	? "Left:", buf2dword(SUBSTR(lcBuffer, 1,4))
	? "Top:", buf2dword(SUBSTR(lcBuffer, 5,4))
	? "Right:", buf2dword(SUBSTR(lcBuffer, 9,4))
	? "Bottom:", buf2dword(SUBSTR(lcBuffer, 13,4))

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[SystemParametersInfo](../libraries/user32/SystemParametersInfo.md)  

## Comment:
Note that the declaration for the SystemParametersInfo varies depending on type of the returned parameter.  
  

***  

