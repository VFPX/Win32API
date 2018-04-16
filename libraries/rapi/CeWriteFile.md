[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeWriteFile
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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
  
***  


## Return value:
Nonzero indicates success.  
***  


## Comments:
See also: [CeSetFilePointer](CeSetFilePointer.md), [CeReadFile](CeReadFile.md) and [CeCloseHandle](CeCloseHandle.md) functions.  
  
***  

