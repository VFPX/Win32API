[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetEnvironmentVariable
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SetEnvironmentVariable function sets the value of an environment variable for the current process.
***  


## Code examples:
[Reading and setting Environment variables](../../samples/sample_152.md)  

## Declaration:
```foxpro  
BOOL SetEnvironmentVariable(
  LPCTSTR lpName,  // environment variable name
  LPCTSTR lpValue  // new value for variable
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetEnvironmentVariable IN kernel32;
	STRING lpName,;
	STRING lpValue  
```  
***  


## Parameters:
lpName 
[in] Pointer to a null-terminated string that specifies the environment variable whose value is being set. 

lpValue 
[in] Pointer to a null-terminated string containing the new value of the specified environment variable.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function has no effect on the system environment variables or the environment variables of other processes.  
  
FoxPro GETENV() function, most likely, retrieves values from an internal array or collection populated during FoxPro shell or application startup. So when you use this API function to add or modify environment variables, the GETENV() may not become aware of this change.  
  
***  

