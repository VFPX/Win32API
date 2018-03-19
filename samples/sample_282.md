[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Setting the mouse capture to the specified window

## Before you begin:
See also:

* [How to Move a Form not using its Titlebar or Caption](sample_195.md)  
  
***  


## Code:
```foxpro  
DO declare

* testing the capture
? GetCapture()

* setting the mouse capture to the window with the keyboard focus
? SetCapture(GetFocus())

* testing the capture
? GetCapture()  && returns a window handle

= ReleaseCapture()

PROCEDURE declare
	DECLARE INTEGER SetCapture IN user32 INTEGER hWindow
	DECLARE INTEGER GetCapture IN user32
	DECLARE INTEGER ReleaseCapture IN user32

	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetFocus IN user32  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetCapture](../libraries/user32/GetCapture.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[ReleaseCapture](../libraries/user32/ReleaseCapture.md)  
[SetCapture](../libraries/user32/SetCapture.md)  
