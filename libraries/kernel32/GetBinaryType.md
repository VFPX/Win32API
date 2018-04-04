[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetBinaryType
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Determines whether a file is executable, and if so, what type of executable file it is. That last property determines which subsystem an executable file runs under.

***  


## Code examples:
[Using GetBinaryType (WinNT only) to determine the type of an executable file](../../samples/sample_115.md)  

## Declaration:
```foxpro  
BOOL GetBinaryType (
  LPCTSTR lpApplicationName,  // full file path
  LPDWORD lpBinaryType        // binary type information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetBinaryType IN kernel32;
	STRING    lpApplicationName,;
	INTEGER @ lpBinaryType  
```  
***  


## Parameters:
lpApplicationName 
[in] Pointer to a null-terminated string that contains the full path of the file whose binary type the function shall determine. 

lpBinaryType 
[out] Pointer to a variable to receive information about the executable type of the file specified by lpApplicationName.  
***  


## Return value:
If the file is executable, the return value is nonzero.  
***  


## Comments:
WinNT only.  
  
***  

