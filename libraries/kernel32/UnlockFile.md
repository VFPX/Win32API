<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UnlockFile
Group: File Management - Library: kernel32    
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
```txt  
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
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

