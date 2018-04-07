[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MoveFileTransacted
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Moves an existing file or a directory, including its children, as a transacted operation.
***  


## Declaration:
```foxpro  
BOOL WINAPI MoveFileTransacted(
	__in      LPCTSTR lpExistingFileName,
	__in_opt  LPCTSTR lpNewFileName,
	__in_opt  LPPROGRESS_ROUTINE lpProgressRoutine,
	__in_opt  LPVOID lpData,
	__in      DWORD dwFlags,
	__in      HANDLE hTransaction
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MoveFileTransacted IN kernel32;
	STRING lpExistingFileName,;
	STRING lpNewFileName,;
	INTEGER lpProgressRoutine,;
	INTEGER lpData,;
	LONG dwFlags,;
	INTEGER hTransaction  
```  
***  


## Parameters:
lpExistingFileName [in]
The current name of the existing file or directory on the local computer.

lpNewFileName [in, optional]
The new name for the file or directory. The new name must not already exist. A new file may be on a different file system or drive. A new directory must be on the same drive.

lpProgressRoutine [in, optional]
A pointer to a CopyProgressRoutine callback function that is called each time another portion of the file has been moved.

lpData [in, optional]
An argument to be passed to the CopyProgressRoutine callback function. This parameter can be NULL.

dwFlags [in]
The move options. This parameter can be one of several predefined values.

hTransaction [in]
A handle to the transaction. This handle is returned by the CreateTransaction function.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Minimal OS: Vista  
  
The new name must not already exist. A new file may be on a different file system or drive.   
  
A new directory must be on the same drive. Otherwise consider using SHFileOperation.  
  
See also: [CreateTransaction](../ktmw32/CreateTransaction.md), [CommitTransaction](../ktmw32/CommitTransaction.md), [RollbackTransaction](../ktmw32/RollbackTransaction.md), [MoveFile](../kernel32/MoveFile.md), [SHFileOperation](../shell32/SHFileOperation.md).  
  
***  

