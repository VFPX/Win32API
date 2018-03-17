<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : MoveFile
Group: File Management - Library: kernel32    
***  


#### The MoveFile function moves an existing file or a directory, including its children.

To specify how to move the file, use the MoveFileEx function
***  


## Code examples:
[Creating a file, then moving it to another destination](../../samples/sample_015.md)  

## Declaration:
```foxpro  
BOOL MoveFile(
  LPCTSTR lpExistingFileName, // file name
  LPCTSTR lpNewFileName       // new file name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MoveFile IN kernel32;
	STRING lpExistingFileName,;
	STRING lpNewFileName
  
```  
***  


## Parameters:
```txt  
lpExistingFileName
[in] Pointer to a null-terminated string that names an existing file or directory

lpNewFileName
[in] Pointer to a null-terminated string that specifies the new name of a file or directory
  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero  
***  


## Comments:
MSDN: the MoveFile function will move (rename) either a file or a directory (including its children) either in the same directory or across directories.   
  
The one caveat is that the MoveFile function will fail on directory moves when the destination is on a different volume -- use SHFileOperation instead.  
  
See also: CopyFile, DeleteFile, MoveFileTransacted, SHFileOperation   
  
***  

