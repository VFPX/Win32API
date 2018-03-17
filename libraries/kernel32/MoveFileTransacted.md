<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MoveFileTransacted
Group: File Management - Library: kernel32    
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
```txt  
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
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Minimal OS: Vista  
  
The new name must not already exist. A new file may be on a different file system or drive.   
  
A new directory must be on the same drive. Otherwise consider using SHFileOperation.  
  
See also: CreateTransaction, CommitTransaction, RollbackTransaction, MoveFile, SHFileOperation   
  
***  

