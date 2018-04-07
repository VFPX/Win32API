[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateSymbolicLink
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Creates a symbolic link.
***  


## Declaration:
```foxpro  
BOOLEAN WINAPI CreateSymbolicLink(
  __in  LPTSTR lpSymlinkFileName,
  __in  LPTSTR lpTargetFileName,
  __in  DWORD dwFlags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateSymbolicLink IN kernel32;
	STRING lpSymlinkFileName,;
	STRING lpTargetFileName,;
	LONG dwFlags  
```  
***  


## Parameters:
lpSymlinkFileName [in] 
The symbolic link to be created.

lpTargetFileName [in] 
The name of the target for the symbolic link to be created.

dwFlags [in] 
Indicates whether the link target, lpTargetFileName, is a directory (1).
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Minimal OS: Vista.  
  
Symbolic link (symlink, softlink) is very similar to Windows shortcut. It contains information about the destination of the target file.  
  
Hard link is a reference stored in directory structure referring to the target file.  
  
* * *  
If this function fails, you may try to call it starting the VFP in admin mode. Only users with the Create Symbolic Link privilege, which administrators have by default, can create symbolic links.  
  
When creating s symbolic link the system does not check whether the source file exists.   
  
Deleting a symbolic link does not affect the source file. There are no specific function for doing that. Use regular API functions for deleting files.  
  
Windows Vista supports symbolic (and hard) links for both files and directories with the command line utility <Em>mklink</Em>.  
  
The <Em>junction points</Em> in Windows are known starting with Windows 2000.  
  
<a href="http://en.wikipedia.org/wiki/Symbolic_link">Symbolic link on Wikipedia</a>  
  
See also: [CreateHardLink](../kernel32/CreateHardLink.md).  
  
***  

