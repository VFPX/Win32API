[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MoveFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
lpExistingFileName 
[in] Pointer to a null-terminated string that names an existing file or directory

lpNewFileName 
[in] Pointer to a null-terminated string that specifies the new name of a file or directory
  
***  


## Return value:
If the function succeeds, the return value is nonzero  
***  


## Comments:
MSDN: the MoveFile function will move (rename) either a file or a directory (including its children) either in the same directory or across directories.   
  
The one caveat is that the MoveFile function will fail on directory moves when the destination is on a different volume -- use SHFileOperation instead.  
  
See also: [CopyFile](../kernel32/CopyFile.md), [DeleteFile](../kernel32/DeleteFile.md), [MoveFileTransacted](../kernel32/MoveFileTransacted.md), [SHFileOperation](../shell32/SHFileOperation.md).  
  
***  

