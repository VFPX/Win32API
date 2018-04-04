[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateJobObject
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Creates or opens a job object.

***  


## Code examples:
[How to make application automatically close all documents it opened](../../samples/sample_491.md)  

## Declaration:
```foxpro  
HANDLE CreateJobObject(
	LPSECURITY_ATTRIBUTES lpJobAttributes,
	LPCTSTR lpName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateJobObject IN kernel32;
	INTEGER lpJobAttributes,;
	STRING  lpName  
```  
***  


## Parameters:
lpJobAttributes 
[in] Pointer to a SECURITY_ATTRIBUTES structure, can be NULL.

lpName 
[in] Pointer to a null-terminated string specifying the name of the job. If lpName is NULL, the job is created without a name.  
***  


## Return value:
If the function succeeds, the return value is a handle to the job object.  
***  


## Comments:
To assign a process to a job object, use the AssignProcessToJobObject function. To close a job object handle, use the CloseHandle function.  
  
***  

