[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetFilePointerEx
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Moves the file pointer of the specified file.
***  


## Declaration:
```foxpro  
BOOL WINAPI SetFilePointerEx(
  HANDLE hFile,
  LARGE_INTEGER liDistanceToMove,
  PLARGE_INTEGER lpNewFilePointer,
  DWORD dwMoveMethod
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetFilePointerEx IN kernel32;
	INTEGER hFile,;
	LONG liDistanceToMoveLo,;
	LONG liDistanceToMoveHi,;
	STRING @lpNewFilePointer,;
	LONG dwMoveMethod
  
```  
***  


## Parameters:
hFile 
[in] A handle to the file. The file handle must have been created with the GENERIC_READ or GENERIC_WRITE access right.

liDistanceToMove 
[in] The number of bytes to move the file pointer.

lpNewFilePointer 
[out, optional] A pointer to a variable to receive the new file pointer.

dwMoveMethod 
[in] The starting point for the file pointer move.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Note that the number of parameters is different in C and VFP declarations for this function.   
  
My first intention was to declare the second parameter, <Em>liDistanceToMove</Em>, as STRING @, which is the pointer to string. This approach worked in similar situations before but failed in this particular case.  
  
Calvin Hsia in <a href="http://blogs.msdn.com/calvin_hsia/archive/2005/03/18/398749.aspx">his blog`s entry</a> explains why this function must be declared in VFP with rather five input parameters versus four regular ones.  
  
The long integer (8 bytes) input parameter <Em>liDistanceToMove</Em> is passed to this function as two separate input parameters of LONG type (4 bytes each).  
  
***  

