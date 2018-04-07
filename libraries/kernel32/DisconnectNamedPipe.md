[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DisconnectNamedPipe
Group: [Pipe](../../functions_group.md#Pipe)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hNamedPipe 
[in] A handle to an instance of a named pipe. This handle must be created by the CreateNamedPipe function.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [ConnectNamedPipe](../kernel32/ConnectNamedPipe.md), [FlushFileBuffers](../kernel32/FlushFileBuffers.md), [CloseHandle](../kernel32/CloseHandle.md).  
  
***  

