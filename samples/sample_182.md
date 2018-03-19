[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Setting properties of the window: caption and user-defined value

## Code:
```foxpro  
DO decl

#DEFINE SW_SHOWNORMAL        1
#DEFINE GWL_USERDATA       -21
#DEFINE ccCustomTitle      "Calc-U-lator"

LOCAL hCalc, lnCounter
	
* retrieve window hanlde to Windows Calculator
hCalc = GetCalcWinHandle()

* change the text of the title bar
= SetWindowText (hCalc, ccCustomTitle)
	
* retrieve the user data associated with the window
lnCounter = GetWindowLong (hCalc, GWL_USERDATA)

* increment value
lnCounter = lnCounter + 1
? "User-data value:", lnCounter

* set it back
? SetWindowLong (hCalc, GWL_USERDATA, lnCounter)  && optional value

FUNCTION  GetCalcWinHandle
	LOCAL hwnd
	hwnd = FindWindow (.NULL., ccCustomTitle)
	IF hwnd = 0
	* start the calculator if not found
		= WinExec ("calc.exe", SW_SHOWNORMAL)
		hwnd = FindWindow (.NULL., "Calculator")
	ENDIF
RETURN hwnd

PROCEDURE  decl
	DECLARE INTEGER SetWindowLong IN user32;
		INTEGER hWnd, INTEGER nIndex, INTEGER dwNewLong

	DECLARE INTEGER FindWindow IN user32;
		STRING lpClassName, STRING lpWindowName

	DECLARE INTEGER GetWindowLong IN user32;
		INTEGER hWnd, INTEGER nIndex
	
	DECLARE INTEGER WinExec IN kernel32;
		STRING  lpCmdLine, INTEGER nCmdShow

	DECLARE INTEGER SetWindowText IN user32;
		INTEGER hWnd, STRING lpString  
```  
***  


## Listed functions:
[FindWindow](../libraries/user32/FindWindow.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  
[SetWindowLong](../libraries/user32/SetWindowLong.md)  
[SetWindowText](../libraries/user32/SetWindowText.md)  
[WinExec](../libraries/kernel32/WinExec.md)  
