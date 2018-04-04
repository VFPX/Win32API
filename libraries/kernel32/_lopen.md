[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : _lopen
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Opens an existing file and sets the file pointer to the beginning of the file.
***  


## Code examples:
[A procedure for setting file times](../../samples/sample_128.md)  

## Declaration:
```foxpro  
HFILE _lopen(
	LPCSTR  lpPathName,	// address of name of file to open
	int  iReadWrite 	// file access mode
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER _lopen IN kernel32;
	STRING  lpFileName, INTEGER iReadWrite  
```  
***  


## Parameters:
lpPathName
Points to a null-terminated string that names the file to open. The string must consist of characters from the Windows ANSI character set. 

iReadWrite
Specifies the modes in which to open the file.  
***  


## Return value:
If the function succeeds, the return value is a file handle. If the function fails, the return value is HFILE_ERROR  
***  


## Comments:
This function is provided for compatibility with 16-bit versions of Windows. Win32-based applications should use the CreateFile function.  
  
***  

