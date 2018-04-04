[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PostQuitMessage
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Indicates to the system that a thread has made a request to terminate (quit). It is typically used in response to a WM_DESTROY message.
***  


## Declaration:
```foxpro  
VOID PostQuitMessage(
  int nExitCode   // exit code
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE PostQuitMessage IN user32 INTEGER nExitCode  
```  
***  


## Parameters:
nExitCode 
[in] Specifies an application exit code. This value is used as the wParam parameter of the WM_QUIT message.  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
Calling PostQuitMessage within FoxPro application acts like ExitProcess -- it closes VFP. The difference that I can see between them (one affects a thread, another -- the whole process), probably is less important in VFP.  
  
***  

