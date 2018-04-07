[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WriteConsole
Group: [Console](../../functions_group.md#Console)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The WriteConsole function writes a character string to a console screen buffer beginning at the current cursor location.
***  


## Code examples:
[Saying "Hello World!" with VFP and WinAPI](../../samples/sample_119.md)  
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL WriteConsole(
  HANDLE hConsoleOutput,
  const VOID* lpBuffer,
  DWORD nNumberOfCharsToWrite,
  LPDWORD lpNumberOfCharsWritten,
  LPVOID lpReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WriteConsole IN kernel32;
	INTEGER   hConsoleOutput,;
	STRING  @ lpBuffer,;
	INTEGER   nNumberOfCharsToWrite,;
	INTEGER @ lpNumberOfCharsWritten,;
	INTEGER   lpReserved
  
```  
***  


## Parameters:
hConsoleOutput 
[in] Handle to the console screen buffer.

lpBuffer 
[in] Pointer to a buffer that contains characters to be written to the console screen buffer.

nNumberOfCharsToWrite 
[in] Number of TCHARs to write. 

lpNumberOfCharsWritten 
[out] Pointer to a variable that receives the number of TCHARs actually written. 

lpReserved 
Reserved; must be NULL.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The total size of the buffer must be less than 64K.  
  
Use GetStdHandle with STD_OUTPUT_HANDLE to obtain the handle to the console screen buffer. Also you may create a screen buffer and attach it to the console.  
  
See also: [GetConsoleScreenBufferInfo](../kernel32/GetConsoleScreenBufferInfo.md), [ReadConsole](../kernel32/ReadConsole.md), [SetConsoleCP](..//SetConsoleCP.md), [SetConsoleCursorPosition](../kernel32/SetConsoleCursorPosition.md), [SetConsoleTextAttribute](../kernel32/SetConsoleTextAttribute.md), [WriteFile](../kernel32/WriteFile.md).  
  
***  

