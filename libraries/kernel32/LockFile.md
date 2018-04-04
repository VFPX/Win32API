[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LockFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Locks a region in an open file. Locking a region prevents other processes from accessing the region.
***  


## Code examples:
[Locking and unlocking file of a VFP table](../../samples/sample_154.md)  

## Declaration:
```foxpro  
BOOL LockFile(
  HANDLE hFile,                   // handle to file
  DWORD dwFileOffsetLow,          // low-order word of offset
  DWORD dwFileOffsetHigh,         // high-order word of offset
  DWORD nNumberOfBytesToLockLow,  // low-order word of length
  DWORD nNumberOfBytesToLockHigh  // high-order word of length
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LockFile IN kernel32;
	INTEGER hFile,;
	INTEGER dwFileOffsetLow,;
	INTEGER dwFileOffsetHigh,;
	INTEGER nNumberOfBytesToLockLow,;
	INTEGER nNumberOfBytesToLockHigh  
```  
***  


## Parameters:
hFile 
[in] Handle to the file with a region to be locked. The file handle must have been created with GENERIC_READ or GENERIC_WRITE access to the file (or both). 

dwFileOffsetLow 
[in] Specifies the low-order word of the starting byte offset in the file where the lock should begin. 

dwFileOffsetHigh 
[in] Specifies the high-order word of the starting byte offset in the file where the lock should begin. 

nNumberOfBytesToLockLow 
[in] Specifies the low-order word of the length of the byte range to be locked. 

nNumberOfBytesToLockHigh 
[in] Specifies the high-order word of the length of the byte range to be locked.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
MSDN: If LockFile cannot lock a region of a file, it returns zero immediately. It does not block. To issue a file lock request that will block until the lock is acquired, use LockFileEx without LOCKFILE_FAIL_IMMEDIATELY.  
  
***  

