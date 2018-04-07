[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FillConsoleOutputAttribute
Group: [Console](../../functions_group.md#Console)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FillConsoleOutputAttribute function sets the character attributes for a specified number of character cells, beginning at the specified coordinates in a screen buffer.
***  


## Code examples:
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL FillConsoleOutputAttribute(
  HANDLE hConsoleOutput,
  WORD wAttribute,
  DWORD nLength,
  COORD dwWriteCoord,
  LPDWORD lpNumberOfAttrsWritten
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FillConsoleOutputAttribute IN kernel32;
	INTEGER hConsoleOutput,;
	SHORT   wAttribute,;
	INTEGER nLength,;
	SHORT   x,;
	SHORT   y,;
	INTEGER lpNumberOfAttrsWritten
  
```  
***  


## Parameters:
hConsoleOutput 
[in] Handle to a console screen buffer.

wAttribute 
[in] Attributes to use when writing to the console screen buffer. 

nLength 
[in] Number of character cells to be set to the specified color attributes. 

dwWriteCoord 
[in] A COORD structure that specifies the console screen buffer coordinates of the first cell whose attributes are to be set. 

lpNumberOfAttrsWritten 
[out] Pointer to a variable that receives the number of character cells whose attributes were actually set.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Normally I would declare COORD dwWriteCoord as STRING @dwCursorPosition. It did not work this way. Fortunately SHORT, SHORT does the job.  
  
See also: [FillConsoleOutputCharacter](../kernel32/FillConsoleOutputCharacter.md), [SetConsoleTextAttribute](../kernel32/SetConsoleTextAttribute.md).  
  
***  

