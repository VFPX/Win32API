<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetEnvironmentVariable
Group: Process and Thread - Library: kernel32    
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
```txt  
lpName
[in] Pointer to a null-terminated string that specifies the environment variable whose value is being set.

lpValue
[in] Pointer to a null-terminated string containing the new value of the specified environment variable.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function has no effect on the system environment variables or the environment variables of other processes.  
  
FoxPro GETENV() function, most likely, retrieves values from an internal array or collection populated during FoxPro shell or application startup. So when you use this API function to add or modify environment variables, the GETENV() may not become aware of this change.  
  
***  

