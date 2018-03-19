[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the MessageBox Win32 function

## Code:
```foxpro  
* MessageBox() Flags
#DEFINE MB_OK                 0
#DEFINE MB_OKCANCEL           1
#DEFINE MB_ABORTRETRYIGNORE   2
#DEFINE MB_YESNOCANCEL        3
#DEFINE MB_YESNO              4
#DEFINE MB_RETRYCANCEL        5

*| icons
#DEFINE MB_ICONSTOP          16
#DEFINE MB_ICONQUESTION      32
#DEFINE MB_ICONEXCLAMATION   48
#DEFINE MB_ICONINFORMATION   64
#DEFINE MB_USERICON         128

*| default buttons
#DEFINE MB_DEFBUTTON1 0
#DEFINE MB_DEFBUTTON2 0x100
#DEFINE MB_DEFBUTTON3 0x200
#DEFINE MB_DEFBUTTON4 0x300

*| modality
#DEFINE MB_APPLMODAL          0
#DEFINE MB_SYSTEMMODAL  0x1000
#DEFINE MB_TASKMODAL  0x2000
#DEFINE MB_HELP  0x4000  && Help Button

*| misc
#DEFINE MB_NOFOCUS  0x8000
#DEFINE MB_SETFOREGROUND  0x10000
#DEFINE MB_DEFAULT_DESKTOP_ONLY 0x20000

*| positioning
#DEFINE MB_TOPMOST  0x40000
#DEFINE MB_RIGHT  0x80000
#DEFINE MB_RTLREADING 0x100000

*| notif.
#DEFINE MB_SERVICE_NOTIFICATION   0x200000
#DEFINE MB_SERVICE_NOTIFICATION_NT3X   0x40000

*| masks
#DEFINE MB_TYPEMASK  0x0f
#DEFINE MB_ICONMASK 0xF0
#DEFINE MB_DEFMASK 0xF00
#DEFINE MB_MODEMASK 0x3000
#DEFINE MB_MISCMASK 0xC000

	DECLARE INTEGER MessageBox IN user32 As MsgBox;
		INTEGER hwnd,;
		STRING  lpText,;
		STRING  lpCaption,;
		INTEGER wType

	DECLARE INTEGER GetActiveWindow IN user32

	hwnd = GetActiveWindow()
	? MsgBox (0, "Message Text", "Message Caption",;
		MB_ABORTRETRYIGNORE + MB_ICONEXCLAMATION +;
		MB_DEFBUTTON3 + MB_SYSTEMMODAL)  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[MessageBox](../libraries/user32/MessageBox.md)  

## Comment:
In this example the dialog box is placed above all open windows.   
  
The main window of VFP is unavailable for input while the dialog exists. But all other open windows are accessible, though the dialog window keeps staying on the top.  
  
After closing the dialog, the VFP main window may not acquire a focus automatically, depending on both OS and VFP versions in use.  
  
Notice that  HWND value used in this example is zero. That means that the dialog has no parent window. You can find HWND of the VFP Main window through the GetActiveWindow, or GetFocus (conditionally) functions.  
  
A HWND passed to this function as a parameter -- I guess -- implies that you can take this value from any other window.   
  
***  

