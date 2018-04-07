[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ReadDirectoryChangesW
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The ReadDirectoryChangesW function retrieves information describing the changes occurring within a directory.
***  


## Code examples:
[Monitoring changes occurring within a directory](../../samples/sample_400.md)  

## Declaration:
```foxpro  
BOOL ReadDirectoryChangesW(
  HANDLE hDirectory,
  LPVOID lpBuffer,
  DWORD nBufferLength,
  BOOL bWatchSubtree,
  DWORD dwNotifyFilter,
  LPDWORD lpBytesReturned,
  LPOVERLAPPED lpOverlapped,
  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReadDirectoryChangesW IN kernel32;
	INTEGER   hDirectory,;
	STRING  @ lpBuffer,;
	INTEGER   nBufferLength,;
	INTEGER   bWatchSubtree,;
	INTEGER   dwNotifyFilter,;
	INTEGER @ lpBytesReturned,;
	INTEGER   lpOverlapped,;
	INTEGER   lpCompletionRoutine
  
```  
***  


## Parameters:
hDirectory 
[in] Handle to the directory to be monitored. This directory must be opened with the FILE_LIST_DIRECTORY access right.

lpBuffer 
[in, out] Pointer to the formatted buffer in which the read results are to be returned.

nBufferLength 
[in] Length of the buffer pointed to by the lpBuffer parameter, in bytes. 

bWatchSubtree 
[in] If this parameter is TRUE, the function monitors the directory tree rooted at the specified directory.

dwNotifyFilter 
[in] Filter criteria the function checks to determine if the wait operation has completed.

lpBytesReturned 
[out] For synchronous calls, this parameter receives the number of bytes transferred into the lpBuffer parameter.

lpOverlapped 
[in] Pointer to an OVERLAPPED structure that supplies data to be used during asynchronous operation. 

lpCompletionRoutine 
[in] Pointer to a completion routine to be called when the operation has been completed or canceled and the calling thread is in an alertable wait state.  
***  


## Return value:
If the function succeeds, the return value is nonzero. For synchronous calls, this means that the operation succeeded. For asynchronous calls, this indicates that the operation was successfully queued.

If the function fails, the return value is zero. To get extended error information, call GetLastError.
  
***  


## Comments:
Deleting a directory with subdirectories into the Recycle Bin produces a single FILE_NOTIFY_INFORMATION structure with the directory data. While a direct delete (the Recycle Bin is bypassed) triggers ReadDirectoryChangesW for each subdirectory, and finally for the directory.  
  
See also: [NetFileEnum](../netapi32/NetFileEnum.md), [FindFirstChangeNotification](../kernel32/FindFirstChangeNotification.md).  
  
***  

