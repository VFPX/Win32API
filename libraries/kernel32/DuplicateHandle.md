[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DuplicateHandle
Group: [Handle and Object](../../functions_group.md#Handle_and_Object)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The DuplicateHandle function duplicates an object handle.

***  


## Code examples:
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  

## Declaration:
```foxpro  
BOOL DuplicateHandle(
  HANDLE hSourceProcessHandle,
  HANDLE hSourceHandle,
  HANDLE hTargetProcessHandle,
  LPHANDLE lpTargetHandle,
  DWORD dwDesiredAccess,
  BOOL bInheritHandle,
  DWORD dwOptions
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DuplicateHandle IN kernel32;
	INTEGER   hSourceProcessHandle,;
	INTEGER   hSourceHandle,;
	INTEGER   hTargetProcessHandle,;
	INTEGER @ lpTargetHandle,;
	INTEGER   dwDesiredAccess,;
	INTEGER   bInheritHandle,;
	INTEGER   dwOptions
  
```  
***  


## Parameters:
hSourceProcessHandle 
[in] Handle to the process with the handle to duplicate.

hSourceHandle 
[in] Handle to duplicate. This is an open object handle that is valid in the context of the source process.

hTargetProcessHandle 
[in] Handle to the process that is to receive the duplicated handle.

lpTargetHandle 
[out] Pointer to a variable that receives the duplicate handle. This handle value is valid in the context of the target process.

dwDesiredAccess 
[in] Access requested for the new handle.

bInheritHandle 
[in] Indicates whether the handle is inheritable.

dwOptions 
[in] Optional actions.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The duplicate handle refers to the same object as the original handle. Therefore, any changes to the object are reflected through both handles. For example, the current file mark for a file handle is always the same for both handles.  
  
***  

