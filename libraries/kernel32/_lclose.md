[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : _lclose
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Closes the specified file so that it is no longer available for reading or writing.
***  


## Code examples:
[A procedure for setting file times](../../samples/sample_128.md)  

## Declaration:
```foxpro  
HFILE _lclose(
	HFILE  hFile 	// handle of file to close
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER _lclose IN kernel32 INTEGER hFile  
```  
***  


## Parameters:
hFile
Identifies the file to be closed. This handle is returned by the function that created or last opened the file.  
***  


## Return value:
If the function succeeds, the return value is zero. If the function fails, the return value is HFILE_ERROR.  
***  


## Comments:
This function is provided for compatibility with 16-bit versions of Windows. Win32-based applications should use the CloseHandle function.  
  
***  

