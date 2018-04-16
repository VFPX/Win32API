[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetConsoleScreenBufferInfo
Group: [Console](../../functions_group.md#Console)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetConsoleScreenBufferInfo function retrieves information about the specified console screen buffer.
***  


## Code examples:
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL GetConsoleScreenBufferInfo(
  HANDLE hConsoleOutput,
  PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetConsoleScreenBufferInfo IN kernel32;
	INTEGER  hConsoleOutput,;
	STRING @ lpConsoleScreenBufferInfo
  
```  
***  


## Parameters:
hConsoleOutput 
[in] Handle to a console screen buffer. 

lpConsoleScreenBufferInfo 
[out] Pointer to a CONSOLE_SCREEN_BUFFER_INFO structure that receives the console screen buffer information.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
```cpp
typedef struct _CONSOLE_SCREEN_BUFFER_INFO {  
  COORD dwSize;               0:4  
  COORD dwCursorPosition;     4:4  
  WORD wAttributes;           8:2  
  SMALL_RECT srWindow;       10:8  
  COORD dwMaximumWindowSize; 18:4  
} CONSOLE_SCREEN_BUFFER_INFO; total 22 bytes
```
  
***  

