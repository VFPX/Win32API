<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RegisterServiceProcess
Group: Process and Thread - Library: kernel32    
***  


#### The RegisterServiceProcess function registers or unregisters a service process. A service process continues to run after the user logs off. 
***  


## Code examples:
[How to hide your program from the Close Program dialog (Win9* only)](../../samples/sample_277.md)  

## Declaration:
```foxpro  
DWORD RegisterServiceProcess(
  DWORD dwProcessId,
  DWORD dwType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegisterServiceProcess IN kernel32;
	INTEGER dwProcessId,;
	INTEGER dwType
  
```  
***  


## Parameters:
```txt  
dwProcessId
Specifies the identifier of the process to register as a service process. Specifies NULL to register the current process.

dwType
Specifies whether the service is to be registered or unregistered.  
```  
***  


## Return value:
The return value is 1 if successful or 0 if an error occurs.  
***  


## Comments:
WinNT - unsupported.  
Windows 95/98/Me only.  
  
***  

