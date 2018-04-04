[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LoadLibrary
Group: [Dynamic-Link Library](../../functions_group.md#Dynamic-Link_Library)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
lpFileName 
[in] Pointer to a null-terminated string that names the executable module (either a .dll or .exe file).  
***  


## Return value:
If the function succeeds, the return value is a handle to the module  
***  


## Comments:
Once you get a return from this function, you probably know how to use it  
  
***  

