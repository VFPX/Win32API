[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetCurrentDirectory
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SetCurrentDirectory function changes the current directory for the current process.
***  


## Code examples:
[Current directory of the application](../../samples/sample_004.md)  

## Declaration:
```foxpro  
BOOL SetCurrentDirectory(
  LPCTSTR lpPathName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetCurrentDirectory IN kernel32;
	STRING lpPathName

  
```  
***  


## Parameters:
lpPathName 
[in] Pointer to a null-terminated string that specifies the path to the new current directory.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

