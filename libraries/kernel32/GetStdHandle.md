
## Function name : GetStdHandle
Group: Console - Library: kernel32    
***  


#### The GetStdHandle function retrieves a handle for the standard input, standard output, or standard error device.
***  


## Code examples:
[Saying "Hello World!" with VFP and WinAPI](../../samples/sample_119.md)  
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
HANDLE GetStdHandle(
  DWORD nStdHandle
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetStdHandle IN kernel32;
	LONG nStdHandle  
```  
***  


## Parameters:
nStdHandle 
[in] Standard device for which a handle is to be returned.
  
***  


## Return value:
If the function succeeds, the return value is a handle to the specified device, or a redirected handle set by a previous call to SetStdHandle.  
***  


## Comments:
See also:  SetStdHandle, WriteConsole, WriteFile, CloseHandle.  
  
***  

