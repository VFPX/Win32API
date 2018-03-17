<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LoadLibrary
Group: Dynamic-Link Library - Library: kernel32    
***  


#### The LoadLibrary function maps the specified executable module into the address space of the calling process.


***  


## Code examples:
[Using LoadLibrary](../../samples/sample_007.md)  
[Loading a string resource from an executable file](../../samples/sample_213.md)  

## Declaration:
```foxpro  
HMODULE LoadLibrary(
  LPCTSTR lpFileName   // file name of module
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LoadLibrary IN kernel32;
	STRING lpLibFileName  
```  
***  


## Parameters:
```txt  
lpFileName
[in] Pointer to a null-terminated string that names the executable module (either a .dll or .exe file).  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the module  
***  


## Comments:
Once you get a return from this function, you probably know how to use it  
  
***  

