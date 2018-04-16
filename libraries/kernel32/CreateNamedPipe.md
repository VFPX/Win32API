[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateNamedPipe
Group: [Pipe](../../functions_group.md#Pipe)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Creates an instance of a named pipe and returns a handle for subsequent pipe operations. 
***  


## Code examples:
[Using named pipes for interprocess communication](../../samples/sample_522.md)  

## Declaration:
```foxpro  
HANDLE CreateNamedPipe(
	LPCTSTR lpName,
	DWORD dwOpenMode,
	DWORD dwPipeMode,
	DWORD nMaxInstances,
	DWORD nOutBufferSize,
	DWORD nInBufferSize,
	DWORD nDefaultTimeOut,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateNamedPipe IN kernel32;
	STRING lpName,;
	LONG dwOpenMode,;
	LONG dwPipeMode,;
	LONG nMaxInstances,;
	LONG nOutBufferSize,;
	LONG nInBufferSize,;
	LONG nDefaultTimeOut,;
	INTEGER lpSecurityAttributes  
```  
***  


## Parameters:
lpName 
[in] The unique pipe name.

dwOpenMode 
[in] The pipe access mode, the overlapped mode, the write-through mode, and the security access mode of the pipe handle.

dwPipeMode 
[in] The type, read, and wait modes of the pipe handle.

nMaxInstances 
[in] The maximum number of instances that can be created for this pipe. 

nOutBufferSize 
[in] The number of bytes to reserve for the output buffer. 

nInBufferSize 
[in] The number of bytes to reserve for the input buffer.

nDefaultTimeOut 
[in] The default time-out value, in milliseconds.

lpSecurityAttributes 
[in] A pointer to a SECURITY_ATTRIBUTES structure that specifies a security descriptor for the new named pipe.  
***  


## Return value:
If the function succeeds, the return value is a handle to the server end of a named pipe instance.  
***  


## Comments:
```foxpro
LOCAL hPipe, cPipeName, nOpenMode, nPipeMode  
cPipeName = "\\.\pipe\tpipe"  
  
nOpenMode = BITOR(PIPE_ACCESS_DUPLEX,;  
	FILE_FLAG_FIRST_PIPE_INSTANCE)  
  
nPipeMode = BITOR(PIPE_TYPE_BYTE,;  
	PIPE_READMODE_BYTE, PIPE_WAIT)  
  
hPipe = CreateNamedPipe(m.cPipeName, nOpenMode, nPipeMode,;  
	1, 0x1000, 0x1000,;  
	NMPWAIT_USE_DEFAULT_WAIT, 0)  
  
IF hPipe = INVALID_HANDLE_VALUE  
	? "CreateNamedPipe failed:", GetLastError()  
	RETURN  
ENDIF  
  
= CloseHandle(m.hPipe)
```

***  

