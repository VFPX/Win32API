[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHFileOperation
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Copies, moves, renames, or deletes a file system object.
***  


## Code examples:
[Deleting files into the Recycle Bin](../../samples/sample_321.md)  
[Displaying standard progress dialog box when copying files](../../samples/sample_508.md)  
[How to remove a directory that is not empty](../../samples/sample_541.md)  

## Declaration:
```foxpro  
int SHFileOperation(
	LPSHFILEOPSTRUCT lpFileOp
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHFileOperation IN Shell32;
	STRING @lpFileOp  
```  
***  


## Parameters:
lpFileOp
[in] Address of an <a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/shell/reference/structures/shfileopstruct.asp">SHFILEOPSTRUCT</a> structure that contains information this function needs to carry out the specified operation.  
***  


## Return value:
Returns zero if successful, or nonzero otherwise. 
  
***  


## Comments:
You should use fully-qualified pathnames with this function. Using it with relative path-names is not thread-safe.  
  
When used to delete a file, SHFileOperation will attempt to place the deleted file in the Recycle Bin. If you wish to delete a file and guarantee that it will not be placed in the Recycle Bin, use DeleteFile.  
  
While operating on a file this function displays a standard progress dialog box unless the FOF_SILENT flag is set in fFlags. The lpszProgressTitle parameter sets the title of this dialog.   
  
See also: [CopyFile](../kernel32/CopyFile.md), [CopyFileTransacted](../kernel32/CopyFileTransacted.md), [MoveFile](../kernel32/MoveFile.md), [MoveFileTransacted](../kernel32/MoveFileTransacted.md), [DeleteFile](../kernel32/DeleteFile.md), [DeleteFileTransacted](../kernel32/DeleteFileTransacted.md).  
  
***  

