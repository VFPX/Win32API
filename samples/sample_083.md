[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Disabling mouse and keyboard input for the main VFP window (with the app still running)

## Code:
```foxpro  
DECLARE INTEGER BlockInput IN user32 INTEGER fBlockIt

? BlockInput (1)
? "*** Input blocked"
	
FOR ii=1 TO 10
	DO dataproc
ENDFOR

? BlockInput (0)
? "*** Input unblocked"

PROCEDURE  dataproc
* it is just an emulation of a time-consuming procedure
	LOCAL ii
	WAIT WINDOW NOWAIT "Creating cursor..."
	CREATE CURSOR cs (id N(6), dt D)
	FOR ii=1 TO 10000
		INSERT INTO cs VALUES (ii, date()-ii)
	ENDFOR
	WAIT CLEAR
	? Chr(9) + "- cursor created at " + TTOC (datetime())
	USE IN cs
RETURN  
```  
***  


## Listed functions:
[BlockInput](../libraries/user32/BlockInput.md)  

## Comment:
<font color=#800000>WinNT4, User32.dll of apr-99: Cannot find entry point BlockInput in the DLL.</font>  
  
During the cycle of N times running the DATAPROC, the user input is practically blocked. You can not even access the Task Manager.   
  
Though the good old CTRL+ALT+DEL still can break through. It is quite helpful in case you have a run-time error within this cycle. Otherwise you could not be able to get out.   
  
Note that no key presses reach the keyboard buffer during the blocking. And this is not the delay like the Sleep function creates.  
  
***  

