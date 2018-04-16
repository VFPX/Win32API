[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to access a file using not its name but an alias (hard link)

## Before you begin:
NTFS supports aliases (hard links) for files. Up to 1023 aliases can be created for a file. Each alias, a hard link to the file, is a directory entry. After creating a hard link, you can access the file using not just its name but the alias as well.  

See also:

[Converting long file names to the short format and vice versa](sample_055.md)  

  
***  


## Code:
```foxpro  
DO declare

LOCAL cSource, cLink
cSource = "C:\aa.txt"
cLink = "C:\aa_hl.txt"

IF CreateHardLink(cLink, cSource, 0) = 0
	? "CreateHardLink failed with error", GetLastError()
	RETURN
ELSE
	= ShellExecute(0, "print", cLink, "", "", 3)
	WAIT WINDOW "Press any key to delete the hard link..."
	= DeleteFile(cLink)
ENDIF

PROCEDURE declare
	DECLARE INTEGER CreateHardLink IN kernel32;
		STRING lpFileName, STRING lpExistingFileName,;
		INTEGER lpSecurityAttributes

	DECLARE INTEGER DeleteFile IN kernel32 STRING lpFileName
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER ShellExecute IN shell32;
		INTEGER hwnd, STRING lpOperation,;
		STRING lpFile, STRING lpParameters,;
		STRING lpDirectory, INTEGER nShowCmd  
```  
***  


## Listed functions:
[CreateHardLink](../libraries/kernel32/CreateHardLink.md)  
[DeleteFile](../libraries/kernel32/DeleteFile.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[ShellExecute](../libraries/shell32/ShellExecute.md)  

## Comment:
Need to check whether short names like MYFILE~1.DOC are created as hard links to files with long names.  
  
Some uses for hard links include:  
- Providing different levels of access to a set of files by creating hard links via paths with different Access Control Lists (ACL).   
- Organizing files into different directories without having to copy the data.   
- Different names for the same file can be used to evoke different behavior for applications (including aliases for an application"s own name).  
  
***  

