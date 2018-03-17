<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetEnvironmentStrings
Group: Process and Thread - Library: kernel32    
***  


#### Retrieves the environment block for the current process.

***  


## Code examples:
[Storing the environment strings in cursor](../../samples/sample_089.md)  

## Declaration:
```foxpro  
LPVOID GetEnvironmentStrings(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetEnvironmentStrings IN kernel32  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
The return value is a pointer to an environment block for the current process.  
***  


## Comments:
A process can use this function"s return value to specify the environment address used by the CreateProcess function.  
  
***  

