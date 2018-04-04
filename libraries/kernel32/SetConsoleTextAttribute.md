[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetConsoleTextAttribute
Group: [Console](../../functions_group.md#Console)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SetConsoleTextAttribute function sets the attributes of characters written to the console screen buffer by the WriteFile or WriteConsole function, or echoed by the ReadFile or ReadConsole function. 
***  


## Code examples:
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL SetConsoleTextAttribute(
  HANDLE hConsoleOutput,
  WORD wAttributes
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetConsoleTextAttribute IN kernel32;
	INTEGER hConsoleOutput,;
	SHORT   wAttributes  
```  
***  


## Parameters:
hConsoleOutput 
[in] Handle to a console screen buffer.

wAttributes 
[in] Character attributes.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function affects text written after the function call.  
  
***  

