[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeReadFile
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function reads data from a file, starting at the position indicated by the file pointer. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
BOOL CeReadFile(
  HANDLE hFile,
  LPVOID lpBuffer,
  DWORD nNumberOfBytesToRead,
  LPDWORD lpNumberOfBytesRead,
  LPOVERLAPPED lpOverlapped
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeReadFile IN rapi;
	INTEGER   hFile,;
	STRING  @ lpBuffer,;
	INTEGER   nBytesToRead,;
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
[in] Number of bytes to be read from the file. 

lpNumberOfBytesRead 
[out] Pointer to the number of bytes read.

lpOverlapped 
[in] Unsupported; set to NULL.
  
***  


## Return value:
Nonzero indicates success. The CeReadFile function returns when one of the following is true: the number of bytes requested has been read or an error occurs.  
***  


## Comments:
See also: [CeSetFilePointer](CeSetFilePointer.md), [CeWriteFile](CeWriteFile.md) and [CeCloseHandle](CeCloseHandle.md) functions.  
  
***  

