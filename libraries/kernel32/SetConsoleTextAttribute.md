<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetConsoleTextAttribute
Group: Console - Library: kernel32    
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
```txt  
hConsoleOutput
[in] Handle to a console screen buffer.

wAttributes
[in] Character attributes.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function affects text written after the function call.  
  
***  

