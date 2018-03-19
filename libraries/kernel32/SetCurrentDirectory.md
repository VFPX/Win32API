
## Function name : SetCurrentDirectory
Group: File Management - Library: kernel32    
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

