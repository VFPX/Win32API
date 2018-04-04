[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FreeLibrary
Group: [Dynamic-Link Library](../../functions_group.md#Dynamic-Link_Library)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FreeLibrary function decrements the reference count of the loaded dynamic-link library (DLL). When the reference count reaches zero, the module is unmapped from the address space of the calling process and the handle is no longer valid
***  


## Code examples:
[Using LoadLibrary](../../samples/sample_007.md)  
[Loading a string resource from an executable file](../../samples/sample_213.md)  
[Storing registration key in the resources of an executable file](../../samples/sample_401.md)  
[How to display a user-defined icon in the MessageBox dialog](../../samples/sample_500.md)  
[Exporting DLL icon resources as .ICO files](../../samples/sample_502.md)  

## Declaration:
```foxpro  
BOOL FreeLibrary(
  HMODULE hModule   // handle to DLL module
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FreeLibrary IN kernel32;
	INTEGER hLibModule  
```  
***  


## Parameters:
hModule 
[in] Handle to the loaded DLL module. The LoadLibrary or GetModuleHandle function returns this handle.   
***  


## Return value:
If the function succeeds, the return value is nonzero  
***  


## Comments:
Each process maintains a reference count for each loaded library module. This reference count is incremented each time LoadLibrary is called and is decremented each time FreeLibrary is called.   
  
A DLL module loaded at process initialization due to load-time dynamic linking has a reference count of one. This count is incremented if the same module is loaded by a call to LoadLibrary.  
  
***  

