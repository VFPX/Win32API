[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetComputerName
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SetComputerName function stores a new NetBIOS name for the local computer. The name is stored in the registry and takes effect the next time the user restarts the computer. 
***  


## Declaration:
```foxpro  
BOOL SetComputerName(
  LPCTSTR lpComputerName  // computer name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetComputerName IN kernel32;
	STRING lpComputerName  
```  
***  


## Parameters:
lpComputerName 
[in] Pointer to a null-terminated character string that specifies the name that will be the computer name the next time the computer is started. The name must not be longer than MAX_COMPUTERNAME_LENGTH characters (31).   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

