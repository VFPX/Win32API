[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetFileTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sets the date and time that a file was created, last accessed, or last modified.
***  


## Code examples:
[Setting the date and time that a file was created](../../samples/sample_065.md)  
[A procedure for setting file times](../../samples/sample_128.md)  
[How to set Creation Date/Time for a folder (WinNT)](../../samples/sample_399.md)  

## Declaration:
```foxpro  
BOOL SetFileTime(
  HANDLE hFile,                     // handle to file
  CONST FILETIME *lpCreationTime,   // creation time
  CONST FILETIME *lpLastAccessTime, // last-access time
  CONST FILETIME *lpLastWriteTime   // last-write time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetFileTime IN kernel32.dll;
	INTEGER hFile,;
	STRING @ lpCreationTime,;
	STRING @ lpLastAccessTime,;
	STRING @ lpLastWriteTime  
```  
***  


## Parameters:
hFile 
[in] Handle to the file for which to set the dates and times. The file handle must have been created with GENERIC_WRITE access to the file. 

lpCreationTime 
[in] Pointer to a FILETIME structure that contains the date and time the file was created. 

lpLastAccessTime 
[in] Pointer to a FILETIME structure that contains the date and time the file was last accessed. 

lpLastWriteTime 
[in] Pointer to a FILETIME structure that contains the date and time the file was last written to.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
As I found the VFP function FOPEN() can not create a file handle to be valid for this function, regardless of chosen attributes. So the only way to do it is the Win32 function OpenFile.  
  
***  

