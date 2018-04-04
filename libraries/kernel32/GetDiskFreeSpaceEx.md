[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDiskFreeSpaceEx
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves information about the amount of space available on a disk volume: the total amount of space, the total amount of free space, and the total amount of free space available to the user associated with the calling thread.
***  


## Code examples:
[DiskFreeSpace class](../../samples/sample_100.md)  

## Declaration:
```foxpro  
BOOL GetDiskFreeSpaceEx(
  LPCTSTR lpDirectoryName,                 // directory name
  PULARGE_INTEGER lpFreeBytesAvailable,    // bytes available to caller
  PULARGE_INTEGER lpTotalNumberOfBytes,    // bytes on disk
  PULARGE_INTEGER lpTotalNumberOfFreeBytes // free bytes on disk
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetDiskFreeSpaceEx IN kernel32;
	STRING   lpDirectoryName,;
	STRING @ lpFreeBytesAvailable,;
	STRING @ lpTotalNumberOfBytes,;
	STRING @ lpTotalNumberOfFreeBytes  
```  
***  


## Parameters:
lpDirectoryName 
[in] Pointer to a null-terminated string that specifies a directory on the disk of interest. 

lpFreeBytesAvailable 
[out] Pointer to a variable that receives the total number of free bytes on the disk that are available to the user associated with the calling thread. 

lpTotalNumberOfBytes 
[out] Pointer to a variable that receives the total number of bytes on the disk that are available to the user associated with the calling thread. 

lpTotalNumberOfFreeBytes 
[out] Pointer to a variable that receives the total number of free bytes on the disk.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Before VFP version 7 this function returns more accurate results for large devices comparing to native SYS(2020) and DiskSpace()  
  
***  

