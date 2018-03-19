[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Locking mouse and keyboard input for the VFP application

## Before you begin:
See also:

* [Capturing keyboard activity of another application using the Raw Input API](sample_572.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER GetActiveWindow IN user32

DECLARE INTEGER EnableWindow IN user32;
 INTEGER hwnd,;
 INTEGER fEnable

* get handle of main VFP window
hwnd = GetActiveWindow()

? EnableWindow (hwnd, 0)
? "*** Input blocked - the main VFP window only"
	
FOR ii=1 TO 10
	DO proc1
ENDFOR

? EnableWindow (hwnd, 1)
? "*** Input unblocked"

PROCEDURE  proc1
	LOCAL ii
	WAIT WINDOW NOWAIT "Creating cursor..."
	CREATE CURSOR cs (id N(6), dt D)
	FOR ii=1 TO 10000
		INSERT INTO cs VALUES (ii, date()-ii)
	ENDFOR
	WAIT CLEAR
	? Chr(9) + "- cursor created at " + TTOC (datetime())
RETURN  
```  
***  


## Listed functions:
[EnableWindow](../libraries/user32/EnableWindow.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  

## Comment:
In this example user input is locked for VFP application only. This function works differently then the BlockInput does. The latter locks the window for all processes not just for the active process and thread.  
  
With EnableWindow you can effectively lock a VFP application. But it is more like "you lock the door and throw away the key". To unlock it use the Task Manager, or beforehand submit the instructions to some other application along with the corresponding HWND.  
  
Applied to windowed controls this function can enable or disable them.  
  
***  

