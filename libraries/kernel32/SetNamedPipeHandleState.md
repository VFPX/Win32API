[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetNamedPipeHandleState
Group: [Pipe](../../functions_group.md#Pipe)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sets the read mode and the blocking mode of the specified named pipe. If the specified handle is to the client end of a named pipe and if the named pipe server process is on a remote computer, the function can also be used to control local buffering.

***  


## Code examples:
[Using named pipes for interprocess communication](../../samples/sample_522.md)  

## Declaration:
```foxpro  
BOOL SetNamedPipeHandleState(
	HANDLE hNamedPipe,
	LPDWORD lpMode,
	LPDWORD lpMaxCollectionCount,
	LPDWORD lpCollectDataTimeout
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetNamedPipeHandleState IN kernel32;
	INTEGER hNamedPipe,;
	LONG @lpMode,;
	LONG lpMaxCollectionCount,;
	LONG lpCollectDataTimeout  
```  
***  


## Parameters:
hNamedPipe 
[in] A handle to the named pipe instance.

[in] The new pipe mode. The mode is a combination of a read-mode flag and a wait-mode flag.

lpMaxCollectionCount 
[in] The maximum number of bytes collected on the client computer before transmission to the server.

lpCollectDataTimeout 
[in] The maximum time, in milliseconds, that can pass before a remote named pipe transfers information over the network.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This is a part of pipe client code  
```foxpro
hPipe = CreateFile(cPipename,;  
	BITOR(GENERIC_WRITE, GENERIC_READ),;  
	0, 0, OPEN_EXISTING, 0, 0)  
  
IF hPipe <> INVALID_HANDLE_VALUE  
	nPipeMode = PIPE_READMODE_MESSAGE  
	nResult = SetNamedPipeHandleState(m.hPipe,;  
		@nPipeMode, 0, 0)  
ENDIF
```

***  

