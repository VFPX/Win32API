[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetEndOfFile
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sets the physical file size for the specified file to the current position of the file pointer.
***  


## Declaration:
```foxpro  
BOOL WINAPI SetEndOfFile(
  __in  HANDLE hFile
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetEndOfFile IN kernel32;
	INTEGER hFile  
```  
***  


## Parameters:
hFile [in] 
A handle to the file to be extended or truncated.
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
In the usage example on this page the file is extended by 1024 bytes beyond its current physical length.   
  
Normally the added space is filled with zeroes. Though it is not completely safe to expect it to happen each time.  
  
The function can be used for extending as well as for making files smaller. Be carefull not to test the truncation on files with any importance.  
  
Files can also be truncated to zero size by calling the CreateFile by itself with the TRUNCATE_EXISTING flag.  
  
See also: [SetFileValidData](..//SetFileValidData.md).  
  
***  

