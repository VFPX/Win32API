<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DisconnectNamedPipe
Group: Pipe - Library: kernel32    
***  


#### Disconnects the server end of a named pipe instance from a client process.
***  


## Code examples:
[Using named pipes for interprocess communication](../../samples/sample_522.md)  

## Declaration:
```foxpro  
BOOL DisconnectNamedPipe(
	HANDLE hNamedPipe
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DisconnectNamedPipe IN kernel32;
	INTEGER hNamedPipe  
```  
***  


## Parameters:
```txt  
hNamedPipe
[in] A handle to an instance of a named pipe. This handle must be created by the CreateNamedPipe function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: ConnectNamedPipe, FlushFileBuffers, CloseHandle.  
  
***  

