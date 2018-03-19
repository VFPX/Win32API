[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Changing system colors

## Before you begin:
The code sample changes colors of the window background and active caption for any window bothering to listen for the WM_SYSCOLORCHANGE message broadcasted by the SetSysColors function.  

After running this code sample, you will notice that colors changed in all windows through the OS. That includes even controls like textboxes and comboboxes. Note that the native VFP controls are not windows like for example VB.NET controls. But they do closely follow the system colors when they draw themselves.  

Do not panic and find below how to restore the colors back to their original values.  
  
***  


## Code:
```foxpro  
* note: to reverse the system colors back to normal
* release the oColorTest variable

PUBLIC oColorTest As TColorTest
oColorTest = CREATEOBJECT("TColorTest")
oColorTest.ChangeColors
* end of main

DEFINE CLASS TColorTest As Session
PROTECTED ColorMask, SavedColors, NewColors

PROCEDURE Init
	THIS.declare

PROCEDURE ChangeColors
#DEFINE COLOR_SCROLLBAR 0
#DEFINE COLOR_ACTIVECAPTION 2
#DEFINE COLOR_WINDOW 5
#DEFINE COLOR_WINDOWFRAME 6
#DEFINE COLOR_MENUTEXT 7
#DEFINE COLOR_WINDOWTEXT 8
	* colors for these two elements are to be
	* changed and eventually restored back
	THIS.ColorMask = num2dword(COLOR_WINDOW)+;
		num2dword(COLOR_ACTIVECAPTION)

	* the original colors are saved in the class property
	THIS.SavedColors = num2dword(GetSysColor(COLOR_WINDOW))+;
		num2dword(GetSysColor(COLOR_ACTIVECAPTION))

	* changing the colors
	THIS.NewColors = num2dword(RGB(128,192,230))+;
		num2dword(RGB(192,0,192))

	= SetSysColors(2, THIS.ColorMask, THIS.NewColors)

PROCEDURE Destroy
* making sure that upon releasing the instance
* of the class all colors are restored back
	THIS.RestoreColors

PROCEDURE RestoreColors
	= SetSysColors(2, THIS.ColorMask, THIS.SavedColors)

PROCEDURE declare
	DECLARE INTEGER GetSysColor IN user32 INTEGER nIndex

	DECLARE INTEGER SetSysColors IN user32;
		INTEGER nElements, STRING lpSysColor,;
		STRING lpColorValues

ENDDEFINE

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
```  
***  


## Listed functions:
[GetSysColor](../libraries/user32/GetSysColor.md)  
[SetSysColors](../libraries/user32/SetSysColors.md)  

## Comment:
The code is written in what can be called a safe way -- the system colors are restored back to original values when the instance of the TColorTest class is released. Type CLEAR ALL in the Command Window or simply close the Visual FoxPro to do that.  
  
***  

