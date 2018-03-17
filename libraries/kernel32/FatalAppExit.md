<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FatalAppExit
Group: Error Handling - Library: kernel32    
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
```txt  
uAction
Reserved; must be zero.

lpMessageText
[in] Pointer to a null-terminated string that is displayed in the message box.  
```  
***  


## Return value:
This function does not return a value.   
***  


## Comments:
Even the name of this function I feel some evil in it. Hardly a reason exists to use it. In the succession of the good old QUIT, ExitProcess, TerminateProcess, PostQuitMessage etc. this function can be only the last resort.   
  
I recollect an old joke about a computer frozen so deep that it took to reboot a power station.  
  
***  

