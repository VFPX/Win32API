[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeleteFileTransacted
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Deletes an existing file as a transacted operation.
***  


## Declaration:
```foxpro  
BOOL WINAPI DeleteFileTransacted(
	__in  LPCTSTR lpFileName,
	__in  HANDLE hTransaction
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeleteFileTransacted IN kernel32;
	STRING lpFileName,;
	INTEGER hTransaction  
```  
***  


## Parameters:
lpFileName [in]
The name of the file to be deleted.

hTransaction [in]
A handle to the transaction. This handle is returned by the CreateTransaction function.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Minimal OS: Vista  
  
See also: [RemoveDirectoryTransacted](../kernel32/RemoveDirectoryTransacted.md), [CreateTransaction](../ktmw32/CreateTransaction.md), [CommitTransaction](../ktmw32/CommitTransaction.md), [RollbackTransaction](../ktmw32/RollbackTransaction.md), [DeleteFile](../kernel32/DeleteFile.md).  
  
***  

