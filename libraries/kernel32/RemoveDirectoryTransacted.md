[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RemoveDirectoryTransacted
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Deletes an existing empty directory as a transacted operation.
***  


## Declaration:
```foxpro  
BOOL WINAPI RemoveDirectoryTransacted(
	__in  LPCTSTR lpPathName,
	__in  HANDLE hTransaction
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RemoveDirectoryTransacted IN kernel32;
	STRING lpPathName,;
	INTEGER hTransaction
  
```  
***  


## Parameters:
lpPathName [in]
The path of the directory to be removed. The path must specify an empty directory, and the calling process must have delete access to the directory.

hTransaction [in]
A handle to the transaction. This handle is returned by the CreateTransaction function.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Minimal OS: Vista  
  
To recursively delete the files in a directory, use the SHFileOperation function.  
  
See also: [DeleteFileTransacted](../kernel32/DeleteFileTransacted.md), [CreateTransaction](../ktmw32/CreateTransaction.md), [CommitTransaction](../ktmw32/CommitTransaction.md), [RollbackTransaction](../ktmw32/RollbackTransaction.md), [RemoveDirectory](../kernel32/RemoveDirectory.md).  
  
***  

