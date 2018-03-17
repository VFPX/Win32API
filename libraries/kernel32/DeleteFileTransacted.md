<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DeleteFileTransacted
Group: File Management - Library: kernel32    
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
```txt  
lpFileName [in]
The name of the file to be deleted.

hTransaction [in]
A handle to the transaction. This handle is returned by the CreateTransaction function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Minimal OS: Vista  
  
See also: RemoveDirectoryTransacted, CreateTransaction, CommitTransaction, RollbackTransaction, DeleteFile   
  
***  

