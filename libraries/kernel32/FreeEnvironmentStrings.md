[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FreeEnvironmentStrings
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FreeEnvironmentStrings function frees a block of environment strings.
***  


## Code examples:
[Storing the environment strings in cursor](../../samples/sample_089.md)  

## Declaration:
```foxpro  
BOOL FreeEnvironmentStrings(
  LPTSTR lpszEnvironmentBlock  // envir. strings
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FreeEnvironmentStrings IN kernel32;
	INTEGER lpszEnvBlock  
```  
***  


## Parameters:
lpszEnvironmentBlock 
[in] Pointer to a block of environment strings. The pointer to the block must be obtained by calling the GetEnvironmentStrings function.   
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  

