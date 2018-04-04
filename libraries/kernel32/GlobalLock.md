[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GlobalLock
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GlobalLock function locks a global memory object and returns a pointer to the first byte of the object"s memory block.
***  


## Code examples:
[Copying strings through the global memory block](../../samples/sample_156.md)  
[Opening the Page Setup dialog box to specify the attributes of a printed page](../../samples/sample_272.md)  
[Enumerating network resources](../../samples/sample_313.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  

## Declaration:
```foxpro  
LPVOID GlobalLock(
  HGLOBAL hMem   // handle to global memory object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GlobalLock IN kernel32;
	INTEGER hMem  
```  
***  


## Parameters:
hMem 
[in] Handle to the global memory object. This handle is returned by either the GlobalAlloc or GlobalReAlloc function.  
***  


## Return value:
If the function succeeds, the return value is a pointer to the first byte of the memory block. If the function fails, the return value is NULL. 
  
***  

