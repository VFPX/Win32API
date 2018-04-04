[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UnlockFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Unlocks a region in an open file. Unlocking a region enables other processes to access the region.
***  


## Code examples:
[Locking and unlocking file of a VFP table](../../samples/sample_154.md)  

## Declaration:
```foxpro  
BOOL UnlockFile(
  HANDLE hFile,                    // handle to file
  DWORD dwFileOffsetLow,           // low-order word of start
  DWORD dwFileOffsetHigh,          // high-order word of start
  DWORD nNumberOfBytesToUnlockLow, // low-order word of length
  DWORD nNumberOfBytesToUnlockHigh // high-order word of length
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UnlockFile IN kernel32;
	INTEGER hFile,;
	INTEGER dwFileOffsetLow,;
	INTEGER dwFileOffsetHigh,;
	INTEGER nNumberOfBytesToUnlockLow,;
	INTEGER nNumberOfBytesToUnlockHigh  
```  
***  


## Parameters:
hFile 
[in] Handle to a file that contains a region locked with LockFile. The file handle must have been created with either GENERIC_READ or GENERIC_WRITE access to the file. 

dwFileOffsetLow 
[in] Specifies the low-order word of the starting byte offset in the file where the locked region begins. 

dwFileOffsetHigh 
[in] Specifies the high-order word of the starting byte offset in the file where the locked region begins. 

nNumberOfBytesToUnlockLow 
[in] Specifies the low-order word of the length of the byte range to be unlocked. 

nNumberOfBytesToUnlockHigh 
[in] Specifies the high-order word of the length of the byte range to be unlocked.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

