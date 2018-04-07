[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetConsoleCursorPosition
Group: [Console](../../functions_group.md#Console)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SetConsoleCursorPosition function sets the cursor position in the specified console screen buffer.
***  


## Code examples:
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL SetConsoleCursorPosition(
  HANDLE hConsoleOutput,
  COORD dwCursorPosition
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetConsoleCursorPosition IN kernel32;
	INTEGER hConsoleOutput,;
	SHORT   x,;
	SHORT   y
  
```  
***  


## Parameters:
hConsoleOutput 
[in] Handle to a console screen buffer. 

dwCursorPosition 
[in] A COORD structure that specifies the new cursor position.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Normally I would declare COORD dwCursorPosition as STRING @dwCursorPosition. It did not work this way. Fortunately SHORT, SHORT does the job.  
  
See also: [GetConsoleCursorInfo](..//GetConsoleCursorInfo.md), [GetConsoleScreenBufferInfo](../kernel32/GetConsoleScreenBufferInfo.md), [ReadConsole](../kernel32/ReadConsole.md), [WriteConsole](../kernel32/WriteConsole.md).  
  
***  

