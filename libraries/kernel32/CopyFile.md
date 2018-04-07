[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CopyFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### This function copies an existing file to a new file
***  


## Code examples:
[Using the CopyFile](../../samples/sample_009.md)  

## Declaration:
```foxpro  
BOOL CopyFile(
	LPCTSTR lpExistingFileName,
	LPCTSTR lpNewFileName,
	BOOL bFailIfExists );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CopyFile IN kernel32;
	STRING  lpExistingFileName,;
	STRING  lpNewFileName,;
	INTEGER bFailIfExists
  
```  
***  


## Parameters:
lpExistingFileName 
[in] Long pointer to a null-terminated string that specifies the name of an existing file. 

lpNewFileName 
[in] Long pointer to a null-terminated string that specifies the name of the new file. 

bFailIfExists 
[in] Boolean that specifies how this operation is to proceed if a file of the same name as that specified by lpNewFileName already exists. If this parameter is TRUE and the new file already exists, the function fails. If this parameter is FALSE and the new file already exists, the function overwrites the existing file and succeeds  
***  


## Return value:
Nonzero indicates success. Zero indicates failure  
***  


## Comments:
The native COPY FILE command cannot copy a file that is open (3. File is in use).   
  
With the CopyFile, both the source and the destination can stay open -- like text files modified, DBF files in use and so on -- and still the copying occurs. Of course, any uncommitted changes do not appear in the target file.  
  
To copy files with a progress dialog box use the SHFileOperation function.   
  
See also: [CopyFileTransacted](../kernel32/CopyFileTransacted.md).  
  
***  

