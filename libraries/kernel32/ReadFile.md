[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ReadFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Reads data from a file, starting at the position indicated by the file pointer.
***  


## Code examples:
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[Peer-to-peer LAN messenger built with Mailslot API functions](../../samples/sample_410.md)  
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  
[Using named pipes for interprocess communication](../../samples/sample_522.md)  

## Declaration:
```foxpro  
BOOL ReadFile(
  HANDLE hFile,                // handle to file
  LPVOID lpBuffer,             // data buffer
  DWORD nNumberOfBytesToRead,  // number of bytes to read
  LPDWORD lpNumberOfBytesRead, // number of bytes read
  LPOVERLAPPED lpOverlapped    // overlapped buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReadFile IN kernel32;
	INTEGER   hFile,;
	STRING  @ lpBuffer,;
	INTEGER   nNumberOfBytesToRead,;
	INTEGER @ lpNumberOfBytesRead,;
	INTEGER   lpOverlapped
  
```  
***  


## Parameters:
hFile 
[in] Handle to the file to be read. The file handle must have been created with GENERIC_READ access to the file. 

lpBuffer 
[out] Pointer to the buffer that receives the data read from the file. 

nNumberOfBytesToRead 
[in] Specifies the number of bytes to be read from the file. 

lpNumberOfBytesRead 
[out] Pointer to the variable that receives the number of bytes read. 

lpOverlapped 
[in] Pointer to an OVERLAPPED structure. This structure is required if hFile was created with FILE_FLAG_OVERLAPPED.   
***  


## Return value:
If the function succeeds, the return value is nonzero. If the return value is nonzero and the number of bytes read is zero, the file pointer was beyond the current end of the file at the time of the read operation. 
  
***  


## Comments:
The function also can be used to read messages from a mailslot.  
  
***  

