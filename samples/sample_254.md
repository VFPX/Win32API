[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Drawing Windows frame controls using the DrawFrameControl function

## Before you begin:
![](../images/winframecontrols.png)  

Note that the use of LoadBitmap to load OEM bitmaps is deprecated and is supported only for backwards compatibility. New applications should use DrawFrameControl to draw system elements.  
  
***  


## Code:
```foxpro  
DO declare

#DEFINE DFC_CAPTION    1
#DEFINE DFC_MENU       2
#DEFINE DFC_SCROLL     3
#DEFINE DFC_BUTTON     4
#DEFINE DFC_POPUPMENU  5

#DEFINE DFCS_SCROLLDOWN           1
#DEFINE DFCS_SCROLLLEFT           2
#DEFINE DFCS_SCROLLRIGHT          3
#DEFINE DFCS_SCROLLCOMBOBOX       5
#DEFINE DFCS_SCROLLSIZEGRIP       8
#DEFINE DFCS_SCROLLSIZEGRIPRIGHT 16

PRIVATE hWindow, hDC, lcBuffer
hWindow = GetActiveWindow()
hDC = GetWindowDC(hWindow)

= DrawControl(DFC_SCROLL, DFCS_SCROLLDOWN,          100,100,120,120)
= DrawControl(DFC_SCROLL, DFCS_SCROLLLEFT,          100,130,120,150)
= DrawControl(DFC_SCROLL, DFCS_SCROLLRIGHT,         100,160,120,180)
= DrawControl(DFC_SCROLL, DFCS_SCROLLCOMBOBOX,      100,190,120,210)
= DrawControl(DFC_SCROLL, DFCS_SCROLLSIZEGRIP,      100,220,120,240)
= DrawControl(DFC_SCROLL, DFCS_SCROLLSIZEGRIPRIGHT, 100,250,120,270)

= ReleaseDC(hWindow, hDC)

PROCEDURE  DrawControl
LPARAMETERS lnType, lnState, lnLeft, lnTop, lnRight, lnBottom
	LOCAL hlcBuffer
	lcBuffer = num2dword(lnLeft) + num2dword(lnTop) +;
		num2dword(lnRight) + num2dword(lnBottom)
	= DrawFrameControl(hDC, @lcBuffer, lnType, lnState)
RETURN

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

PROCEDURE  declare
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc

	DECLARE INTEGER DrawFrameControl IN user32;
		INTEGER hdc, STRING @lprc,;
		INTEGER uType, INTEGER uState  
```  
***  


## Listed functions:
[DrawFrameControl](../libraries/user32/DrawFrameControl.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
