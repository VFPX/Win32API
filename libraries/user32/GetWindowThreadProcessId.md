[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWindowThreadProcessId
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the identifier of the thread that created the specified window and, optionally, the identifier of the process that created the window.
***  


## Code examples:
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  

## Declaration:
```foxpro  
DWORD GetWindowThreadProcessId(
  HWND hWnd,             // handle to window
  LPDWORD lpdwProcessId  // process identifier
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowThreadProcessId IN user32;
	INTEGER   hWnd,;
	INTEGER @ lpdwProcId  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window. 

lpdwProcessId 
[out] Pointer to a variable that receives the process identifier.   
***  


## Return value:
The return value is the identifier of the thread that created the window.   
***  


## Comments:
It would be interesting to compare thread Ids obtained from this function for the GetActiveWindow (main VFP window) and the GetFocus, applied to an active VFP form. Will it be just one thread or two different ones?  
  
***  

