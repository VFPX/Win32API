[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WriteFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The WriteFile function writes data to a file and is designed for both synchronous and asynchronous operation. 
***  


## Code examples:
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  
[Using mailslots to send messages on the network](../../samples/sample_269.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[Peer-to-peer LAN messenger built with Mailslot API functions](../../samples/sample_410.md)  
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  
[Using named pipes for interprocess communication](../../samples/sample_522.md)  

## Declaration:
```foxpro  
BOOL WriteFile(
  HANDLE hFile,                    // handle to file
  LPCVOID lpBuffer,                // data buffer
  DWORD nNumberOfBytesToWrite,     // number of bytes to write
  LPDWORD lpNumberOfBytesWritten,  // number of bytes written
  LPOVERLAPPED lpOverlapped        // overlapped buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WriteFile IN kernel32;
	INTEGER   hFile,;
	INTEGER   lpBuffer,;
	INTEGER   nBt2Write,;
	INTEGER @ lpBtWritten,;
	INTEGER   lpOverlapped  
```  
***  


## Parameters:
hFile 
[in] Handle to the file to be written to. The file handle must have been created with GENERIC_WRITE access to the file. 

lpBuffer 
[in] Pointer to the buffer containing the data to be written to the file. 

nNumberOfBytesToWrite 
[in] Specifies the number of bytes to write to the file. 

lpNumberOfBytesWritten 
[out] Pointer to the variable that receives the number of bytes written. 

lpOverlapped 
[in] Pointer to an OVERLAPPED structure. This structure is required if hFile was opened with FILE_FLAG_OVERLAPPED.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The function also can be used to put a message in a mailslot.  
  
***  

