[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetFileAttributes
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sets a file"s attributes.

***  


## Code examples:
[Changing file attributes](../../samples/sample_103.md)  

## Declaration:
```foxpro  
BOOL SetFileAttributes(
  LPCTSTR lpFileName,      // file name
  DWORD dwFileAttributes   // attributes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SetFileAttributes IN kernel32;
	STRING lpFileName,;
	INTEGER dwFileAttributes  
```  
***  


## Parameters:
lpFileName 
[in] Pointer to a string that specifies the name of the file whose attributes are to be set. 

dwFileAttributes 
[in] Specifies the file attributes to set for the file.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
DOS command ATTRIB can be used for the same purpose:  
```txt
ATTRIB -R c:\mydir\*.* /S
```

***  

