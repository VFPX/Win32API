<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ConnectNamedPipe
Group: Pipe - Library: kernel32    
***  


#### Enables a named pipe server process to wait for a client process to connect to an instance of a named pipe. 
***  


## Code examples:
[Using named pipes for interprocess communication](../../samples/sample_522.md)  

## Declaration:
```foxpro  
BOOL ConnectNamedPipe(
	HANDLE hNamedPipe,
	LPOVERLAPPED lpOverlapped
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ConnectNamedPipe IN kernel32;
	INTEGER hNamedPipe,;
	INTEGER lpOverlapped  
```  
***  


## Parameters:
```txt  
hNamedPipe
[in] A handle to the server end of a named pipe instance. This handle is returned by the CreateNamedPipe function.

lpOverlapped
[in] A pointer to an OVERLAPPED structure.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
A client process connects by calling either the CreateFile or CallNamedPipe function.  
  
See also: DisconnectNamedPipe, CloseHandle.  
  
***  

