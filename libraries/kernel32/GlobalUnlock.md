<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GlobalUnlock
Group: Memory Management - Library: kernel32    
***  


#### Decrements the lock count associated with a memory object that was allocated with GMEM_MOVEABLE. This function has no effect on memory objects allocated with GMEM_FIXED.
***  


## Code examples:
[Copying strings through the global memory block](../../samples/sample_156.md)  
[Opening the Page Setup dialog box to specify the attributes of a printed page](../../samples/sample_272.md)  
[Enumerating network resources](../../samples/sample_313.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  

## Declaration:
```foxpro  
BOOL GlobalUnlock(
  HGLOBAL hMem   // handle to global memory object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GlobalUnlock IN kernel32;
	INTEGER hMem  
```  
***  


## Parameters:
```txt  
hMem
[in] Handle to the global memory object. This handle is returned by either the GlobalAlloc or GlobalReAlloc function.  
```  
***  


## Return value:
If the memory object is still locked after decrementing the lock count, the return value is a nonzero value.  
***  

