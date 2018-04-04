[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FatalAppExit
Group: [Error Handling](../../functions_group.md#Error_Handling)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FatalAppExit function displays a message box and terminates the application when the message box is closed. 
***  


## Code examples:
[Terminating VFP application using the FatalAppExit](../../samples/sample_229.md)  

## Declaration:
```foxpro  
VOID FatalAppExit(
  UINT uAction,          // reserved
  LPCTSTR lpMessageText  // display string
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE FatalAppExit IN kernel32;
	INTEGER uAction,;
	STRING  lpMessageText  
```  
***  


## Parameters:
uAction 
Reserved; must be zero. 

lpMessageText 
[in] Pointer to a null-terminated string that is displayed in the message box.   
***  


## Return value:
This function does not return a value.   
***  


## Comments:
Even the name of this function I feel some evil in it. Hardly a reason exists to use it. In the succession of the good old QUIT, ExitProcess, TerminateProcess, PostQuitMessage etc. this function can be only the last resort.   
  
I recollect an old joke about a computer frozen so deep that it took to reboot a power station.  
  
***  

