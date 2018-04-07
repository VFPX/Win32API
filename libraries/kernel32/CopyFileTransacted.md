[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CopyFileTransacted
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Copies an existing file to a new file as a transacted operation, notifying the application of its progress through a callback function.
***  


## Code examples:
[Copying files as a transacted operation (Vista)](../../samples/sample_540.md)  

## Declaration:
```foxpro  
BOOL WINAPI CopyFileTransacted(
  __in      LPCTSTR lpExistingFileName,
  __in      LPCTSTR lpNewFileName,
  __in_opt  LPPROGRESS_ROUTINE lpProgressRoutine,
  __in_opt  LPVOID lpData,
  __in_opt  LPBOOL pbCancel,
  __in      DWORD dwCopyFlags,
  __in      HANDLE hTransaction
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CopyFileTransacted IN kernel32;
	STRING lpExistingFileName,;
	STRING lpNewFileName,;
	INTEGER lpProgressRoutine,;
	INTEGER lpData,;
	INTEGER pbCancel,;
	INTEGER dwCopyFlags,;
	INTEGER hTransaction  
```  
***  


## Parameters:
lpExistingFileName [in] 
The name of an existing file. 

lpNewFileName [in] 
The name of the new file.

lpProgressRoutine [in, optional] 
The address of a callback function of type LPPROGRESS_ROUTINE that is called each time another portion of the file has been copied.

lpData [in, optional] 
The argument to be passed to the callback function. This parameter can be NULL.

pbCancel [in, optional] 
If this flag is set to TRUE during the copy operation, the operation is canceled. Otherwise, the copy operation will continue to completion.

dwCopyFlags [in] 
Flags that specify how the file is to be copied.

hTransaction [in] 
A handle to the transaction.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Requires Windows Vista.   
  
Obviously the callback side of this function cannot be exploited in plain FoxPro code. Thus the <Em>lpProgressRoutine</Em> must be set to 0.  
  
Based on call`s completion (also some application logic may become involved), either CommitTransaction or RollbackTransaction is applied to finalize or cancel the process of copying.  
  
See also: [CreateTransaction](../ktmw32/CreateTransaction.md), [CommitTransaction](../ktmw32/CommitTransaction.md), [RollbackTransaction](../ktmw32/RollbackTransaction.md), [CopyFile](../kernel32/CopyFile.md), [DeleteFileTransacted](../kernel32/DeleteFileTransacted.md).  
  
***  

