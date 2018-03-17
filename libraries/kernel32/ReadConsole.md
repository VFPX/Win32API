<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ReadConsole
Group: Console - Library: kernel32    
***  


#### The ReadConsole function reads character input from the console input buffer and removes it from the buffer.
***  


## Code examples:
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
BOOL ReadConsole(
  HANDLE hConsoleInput,
  LPVOID lpBuffer,
  DWORD nNumberOfCharsToRead,
  LPDWORD lpNumberOfCharsRead,
  LPVOID lpReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReadConsole IN kernel32;
	INTEGER   hConsoleInput,;
	STRING  @ lpBuffer,;
	INTEGER   nNumberOfCharsToRead,;
	INTEGER @ lpNumberOfCharsRead,;
	INTEGER   lpReserved
  
```  
***  


## Parameters:
```txt  
hConsoleInput
[in] Handle to the console input buffer.

lpBuffer
[out] Pointer to a buffer that receives the data read from the console input buffer.

nNumberOfCharsToRead
[in] Number of TCHARs to read.

lpNumberOfCharsRead
[out] Pointer to a variable that receives the number of TCHARs actually read.

lpReserved
[in] Reserved; must be NULL.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The total size of the buffer required will be less than 64K.   
  
Use GetStdHandle with STD_INPUT_HANDLE to obtain the handle to the console input buffer.  
  
See also: WriteConsole.  
  
***  

