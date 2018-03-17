<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FreeEnvironmentStrings
Group: Process and Thread - Library: kernel32    
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
```txt  
lpszEnvironmentBlock
[in] Pointer to a block of environment strings. The pointer to the block must be obtained by calling the GetEnvironmentStrings function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  

