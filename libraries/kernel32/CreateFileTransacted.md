[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateFileTransacted
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Creates or opens a file, file stream, or directory as a transacted operation. The function returns a handle that can be used to access the object.
***  


## Declaration:
```foxpro  
HANDLE WINAPI CreateFileTransacted(
	__in        LPCTSTR lpFileName,
	__in        DWORD dwDesiredAccess,
	__in        DWORD dwShareMode,
	__in_opt    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	__in        DWORD dwCreationDisposition,
	__in        DWORD dwFlagsAndAttributes,
	__in_opt    HANDLE hTemplateFile,
	__in        HANDLE hTransaction,
	__in_opt    PUSHORT pusMiniVersion,
	__reserved  PVOID pExtendedParameter
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateFileTransacted IN kernel32;
	STRING lpFileName,;
	LONG dwDesiredAccess,;
	LONG dwShareMode,;
	INTEGER lpSecurityAttributes,;
	LONG dwCreationDisposition,;
	LONG dwFlagsAndAttributes,;
	INTEGER hTemplateFile,;
	INTEGER hTransaction,;
	INTEGER pusMiniVersion,;
	INTEGER pExtendedParameter  
```  
***  


## Parameters:
lpFileName [in]
The name of an object to be created or opened.

dwDesiredAccess [in]
The access to the object, which can be summarized as read, write, both or neither (zero).

dwShareMode [in]
The sharing mode of an object, which can be read, write, both, delete, all of these, or none (refer to the following table).

lpSecurityAttributes [in, optional]
A pointer to a SECURITY_ATTRIBUTES structure that contains an optional security descriptor and also determines whether or not the returned handle can be inherited by child processes. The parameter can be NULL.

dwCreationDisposition [in]
An action to take on files that exist and do not exist.

dwFlagsAndAttributes [in]
The file attributes and flags, FILE_ATTRIBUTE_NORMAL being the most common default value.

hTemplateFile [in, optional]
A valid handle to a template file with the GENERIC_READ access right. This parameter can be NULL.

hTransaction [in]
A handle to the transaction. This handle is returned by the CreateTransaction function.

pusMiniVersion [in, optional]
The miniversion to be opened. If the transaction specified in hTransaction is not the transaction that is modifying the file, this parameter should be NULL.

pExtendedParameter
This parameter is reserved and must be NULL.  
***  


## Return value:
If the function succeeds, the return value is an open handle to the specified file, device, named pipe, or mail slot.  
***  


## Comments:
Minimal OS: Vista  
  
To perform this operation as a nontransacted operation or to access objects other than files (for example, named pipes, physical devices, mailslots), use the CreateFile function.  
  
See also: [CreateTransaction](../ktmw32/CreateTransaction.md), [CommitTransaction](../ktmw32/CommitTransaction.md), [RollbackTransaction](../ktmw32/RollbackTransaction.md), [CreateFile](../kernel32/CreateFile.md).  
  
***  

