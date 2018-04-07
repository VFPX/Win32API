[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateHardLink
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Establishes a hard link between an existing file and a new file. This function is only supported on the NTFS file system.

***  


## Code examples:
[How to access a file using not its name but an alias (hard link)](../../samples/sample_018.md)  

## Declaration:
```foxpro  
BOOL CreateHardLink(
	LPCTSTR lpFileName,
	LPCTSTR lpExistingFileName,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateHardLink IN kernel32;
	STRING  lpFileName,;
	STRING  lpExistingFileName,;
	INTEGER lpSecurityAttributes  
```  
***  


## Parameters:
lpFileName 
[in] A pointer to the name of a new file. 
This parameter cannot specify the name of a directory.

lpExistingFileName 
[in] A pointer to the name of an existing file to which a link points. 

lpSecurityAttributes 
Reserved; must be NULL.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
An additional hard link that is created with the CreateHardLink function allows you to have multiple directory entries for a file, that is, multiple hard links to the same file, which can be different names in the same directory, or the same or different names in different directories.   
  
However, all hard links to a file must be on the same volume. Also <Em>lpFileName</Em> cannot specify the name of a directory.  
  
<a href="http://en.wikipedia.org/wiki/Hard_link">Hard link on Wikipedia</a>  
  
See also: [CreateSymbolicLink](../kernel32/CreateSymbolicLink.md).  
  
***  

