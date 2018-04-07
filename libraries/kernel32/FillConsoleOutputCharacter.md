[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FillConsoleOutputCharacter
Group: [Console](../../functions_group.md#Console)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FillConsoleOutputCharacter function writes a character to the console screen buffer a specified number of times, beginning at the specified coordinates.
***  


## Code examples:
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL FillConsoleOutputCharacter(
  HANDLE hConsoleOutput,
  TCHAR cCharacter,
  DWORD nLength,
  COORD dwWriteCoord,
  LPDWORD lpNumberOfCharsWritten
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FillConsoleOutputCharacter IN kernel32;
	INTEGER hConsoleOutput,;
	SHORT   cCharacter,;
	INTEGER nLength,;
	SHORT   x,;
	SHORT   y,;
	INTEGER lpNumberOfCharsWritten
  
```  
***  


## Parameters:
hConsoleOutput 
[in] Handle to a console screen buffer.

cCharacter 
[in] Character to write to the console screen buffer. 

nLength 
[in] Number of character cells to which the character should be written. 

dwWriteCoord 
[in] A COORD structure that specifies the console screen buffer coordinates of the first cell to which the character is to be written. 

lpNumberOfCharsWritten 
[out] Pointer to a variable that receives the number of characters actually written to the console screen buffer.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The attribute values at the positions written are not changed. Use the FillConsoleOutputAttribute function to set the characters attribute.  
  
Normally I would declare COORD dwWriteCoord as STRING @dwCursorPosition. It did not work this way. Fortunately SHORT, SHORT does the job.  
  
See also: [FillConsoleOutputAttribute](../kernel32/FillConsoleOutputAttribute.md), [SetConsoleTextAttribute](../kernel32/SetConsoleTextAttribute.md).  
  
***  

