[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to position the GETPRINTER() dialog

## Short description:
The GETPRINTER() dialog normaly appears at the left top corner of the main window of FoxPro. What if you want it to popup in the middle of the screen? The interface has no input parameters that can be used to position the dialog. Still the Timer control and several API calls can solve this small problem.  
***  


## Before you begin:
The GETPRINTER() dialog normaly appears at the left top corner of the main window of FoxPro.  

![](../images/getprinter_dlg.png)  

*What if you want it to popup in the middle of the screen? *  

The interface has no input parameters that can be used to position the dialog. Still the Timer control and several API calls can solve this small problem.  

The same technique is used in another example [Using Extended MessageBox() Class](sample_424.md). First you start a Timer, then call the GETPRINTER(). Amazingly, the Timer keeps ticking behind this otherwise perfectly modal window. So from the Timer event you can access the dialog and move it.  

This is not the ideal solution, because the dialog may "jump" -- *fixed [May 9, 2006] by locking and subsequently unlocking drawing in the Windows desktop*.   

See also:

* [Using Extended MessageBox() Class](sample_424.md)
* [Extended MessageBox Class](sample_418.md)  
* [How to change font name and size in the MessageBox dialog](sample_434.md)  
* [Creating an Open dialog box to specify the drive, directory, and name of a file to open (Shell32 version)](sample_365.md)  
* [Creating the Open dialog box to specify the drive, directory, and name of a file to open](sample_363.md)  
* [Creating the Save dialog box to specify the drive, directory, and name of a file to save](sample_265.md)  
* [How to display a dialog box that enables the user to select a folder (an alternative to the GETDIR)](sample_364.md)  
  
***  


## Code:
```foxpro  
WITH _SCREEN
	IF VARTYPE(.printerdlg) <> "U"
		.RemoveObject("printerdlg")
	ENDIF
	.AddObject("printerdlg", "printerdlg")
	.printerdlg.ShowDialog(.Width-500, .Height-300)

	IF NOT EMPTY(.printerdlg.printername)
		= MESSAGEBOX("Printer selected: " + .printerdlg.printername)
	ENDIF
ENDWITH
* end of main

DEFINE CLASS PrinterDlg As Timer
#DEFINE GETPRINTER_CAPTION "Printer"
PROTECTED xpos, ypos
	hDialog=0
	printername=""

PROCEDURE ShowDialog(nX, nY)
	* Victor Espinoza's suggestion proves correct:
	* locking drawing in the desktop window and unlocking it
	* later in SetPosition method hides the "jump"
	= LockWindowUpdate(GetDesktopWindow())

	THIS.xpos = m.nX
	THIS.ypos = m.nY
	THIS.Interval=100
	THIS.printername = GETPRINTER()

PROCEDURE Init
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER LockWindowUpdate IN user32 INTEGER hWndLock
	DECLARE INTEGER GetDesktopWindow IN user32

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch

	DECLARE INTEGER SetWindowText IN user32;
		INTEGER hWindow, STRING lpString

	DECLARE INTEGER SetWindowPos IN user32;
		INTEGER hwnd, INTEGER hWndInsertAfter, INTEGER x,;
		INTEGER y, INTEGER cx, INTEGER cy, INTEGER wFlags

PROCEDURE Timer
	IF THIS.hDialog = 0
		IF THIS.DialogFound()
			THIS.SetPosition
		ENDIF
		THIS.Interval = 0
	ENDIF

PROTECTED FUNCTION DialogFound
	LOCAL hWindow, cTitle
	hWindow = GetActiveWindow()
	cTitle = THIS.GetWinText(hWindow)
	THIS.hDialog = IIF(cTitle=GETPRINTER_CAPTION, hWindow, 0)
RETURN (THIS.hDialog <> 0)

PROTECTED PROCEDURE SetPosition
#DEFINE HWND_TOP  0
#DEFINE SWP_NOSIZE 1
#DEFINE SWP_SHOWWINDOW 0x40

	= SetWindowPos(THIS.hDialog, HWND_TOP,;
		THIS.xpos, THIS.ypos, 0,0,;
		SWP_SHOWWINDOW+SWP_NOSIZE)

	= SetWindowText(THIS.hDialog, "User-defined dialog caption")

	* unlocks updates in the desktop window;
	* see another call to this function above
	= LockWindowUpdate(0)

PROTECTED FUNCTION GetWinText(hWindow)
	LOCAL nBufsize, cBuffer
	nBufsize = 128
	cBuffer = REPLICATE(Chr(0), nBufsize)
	nBufsize = GetWindowText(hWindow, @cBuffer, nBufsize)
RETURN Iif(nBufsize=0, "", Left(cBuffer, nBufsize))

ENDDEFINE  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetDesktopWindow](../libraries/user32/GetDesktopWindow.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
[LockWindowUpdate](../libraries/user32/LockWindowUpdate.md)  
[SetWindowPos](../libraries/user32/SetWindowPos.md)  
[SetWindowText](../libraries/user32/SetWindowText.md)  

## Comment:
Try this approach with other dialogs, like GETFONT(), GETFILE(). Note that in case of another dialog you must use the window title constant different from GETPRINTER_CAPTION.  
  
Technically, you can even play an AVI on the dialog. Take a look at [How to play AVI file on the _screen](sample_430.md) example. BTW, the *TAvi* also inherits the Timer class.  
  
***  

