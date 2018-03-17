<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeWriteFile
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function writes data to a file on remote Windows CE device.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
BOOL CeWriteFile(
  HANDLE hFile,
  LPCVOID lpBuffer,
  DWORD nNumberOfBytesToWrite,
  LPDWORD lpNumberOfBytesWritten,
  LPOVERLAPPED lpOverlapped
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeWriteFile IN rapi;
	INTEGER   hFile,;
	STRING  @ lpBuffer,;
	INTEGER   nBytesToWrite,;
	INTEGER @ lpBytesWritten,;
	INTEGER   lpOverlapped
  
```  
***  


## Parameters:
```txt  
hFile
[in] Handle to the file to be written to. The file handle must have been created with GENERIC_WRITE access to the file.

lpBuffer
[in] Pointer to the buffer containing the data to be written to the file.

nNumberOfBytesToWrite
[in] Number of bytes to write to the file.

lpNumberOfBytesWritten
[out] Pointer to the number of bytes written by this function call.

lpOverlapped
[in] Unsupported; set to NULL.
  
```  
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
See also CeSetFilePointer, CeReadFile and CeCloseHandle functions.  
  
***  

