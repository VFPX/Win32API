<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PostQuitMessage
Group: Message and Message Queue - Library: user32    
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
```txt  
nExitCode
[in] Specifies an application exit code. This value is used as the wParam parameter of the WM_QUIT message.  
```  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
Calling PostQuitMessage within FoxPro application acts like ExitProcess -- it closes VFP. The difference that I can see between them (one affects a thread, another -- the whole process), probably is less important in VFP.  
  
***  

