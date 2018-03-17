<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetConsoleCursorPosition
Group: Console - Library: kernel32    
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
```txt  
hConsoleOutput
[in] Handle to a console screen buffer.

dwCursorPosition
[in] A COORD structure that specifies the new cursor position.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Normally I would declare COORD dwCursorPosition as STRING @dwCursorPosition. It did not work this way. Fortunately SHORT, SHORT does the job.  
  
See also: GetConsoleCursorInfo, GetConsoleScreenBufferInfo, ReadConsole, WriteConsole.  
  
***  

