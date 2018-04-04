[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileSize
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the size of a specified file.
***  


## Code examples:
[Using GetFileSize](../../samples/sample_114.md)  
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  

## Declaration:
```foxpro  
DWORD GetFileSize(
  HANDLE hFile,           // handle to file
  LPDWORD lpFileSizeHigh  // high-order word of file size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileSize IN kernel32;
	INTEGER   hFile,;
	INTEGER @ lpFileSizeHigh  
```  
***  


## Parameters:
hFile 
[in] Handle to the file whose size is to be returned. 

lpFileSizeHigh 
[out] Pointer to the variable where the high-order word of the file size is returned.  
***  


## Return value:
If the function succeeds, the return value is the low-order doubleword of the file size, and, if lpFileSizeHigh is non-NULL, the function puts the high-order doubleword of the file size into the variable pointed to by that parameter.  
***  


## Comments:
This function stores the file size in two DWORD values. To retrieve a file size stored in a LARGE_INTEGER structure, use the GetFileSizeEx function (WinNT only).   
  
***  

