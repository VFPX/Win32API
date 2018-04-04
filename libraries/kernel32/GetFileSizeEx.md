[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileSizeEx
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetFileSizeEx function retrieves the size of the specified file.
***  


## Code examples:
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  

## Declaration:
```foxpro  
BOOL GetFileSizeEx(
  HANDLE hFile,
  PLARGE_INTEGER lpFileSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileSizeEx IN kernel32;
	INTEGER  hFile,;
	STRING @ lpFileSize  
```  
***  


## Parameters:
hFile 
[in] Handle to the file whose size is to be returned.

lpFileSize 
[out] Pointer to a LARGE_INTEGER structure that receives the file size.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Client: Requires Windows XP or Windows 2000 Professional.  
Server: Requires Windows Server 2003 or Windows 2000 Server.  
  
The LARGE_INTEGER structure is used to represent a 64-bit signed integer value.  
  
***  

