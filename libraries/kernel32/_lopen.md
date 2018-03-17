<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : _lopen
Group: File Management - Library: kernel32    
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
```txt  
lpPathName
Points to a null-terminated string that names the file to open. The string must consist of characters from the Windows ANSI character set.

iReadWrite
Specifies the modes in which to open the file.  
```  
***  


## Return value:
If the function succeeds, the return value is a file handle. If the function fails, the return value is HFILE_ERROR  
***  


## Comments:
This function is provided for compatibility with 16-bit versions of Windows. Win32-based applications should use the CreateFile function.  
  
***  

