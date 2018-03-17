<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CreatePipe
Group: Pipe - Library: kernel32    
***  


#### The CreatePipe function creates an anonymous pipe, and returns handles to the read and write ends of the pipe.

***  


## Code examples:
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  

## Declaration:
```foxpro  
BOOL CreatePipe(
  PHANDLE hReadPipe,
  PHANDLE hWritePipe,
  LPSECURITY_ATTRIBUTES lpPipeAttributes,
  DWORD nSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreatePipe IN kernel32;
	INTEGER @ hReadPipe,;
	INTEGER @ hWritePipe,;
	STRING  @ lpPipeAttributes,;
	LONG      nSize
  
```  
***  


## Parameters:
```txt  
hReadPipe
[out] Pointer to a variable that receives the read handle for the pipe.

hWritePipe
[out] Pointer to a variable that receives the write handle for the pipe.

lpPipeAttributes
[in] Pointer to a SECURITY_ATTRIBUTES structure that determines whether the returned handle can be inherited by child processes.

nSize
[in] Size of the buffer for the pipe, in bytes.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.
  
***  


## Comments:
CreatePipe creates the pipe, assigning the specified pipe size to the storage buffer. CreatePipe also creates handles that the process uses to read from and write to the buffer in subsequent calls to the ReadFile and WriteFile functions.  
  
***  

