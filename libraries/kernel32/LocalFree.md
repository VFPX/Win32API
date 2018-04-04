[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LocalFree
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The LocalFree function frees the specified local memory object and invalidates its handle.
***  


## Code examples:
[Creating a folder](../../samples/sample_001.md)  
[Retrieving local computer and user names](../../samples/sample_041.md)  
[Retrieving System Error message strings](../../samples/sample_056.md)  
[StrDup returns a pointer to the duplicate of a source VFP string](../../samples/sample_181.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)](../../samples/sample_360.md)  
[GetFileOwner - Get the owner of an NTFS file](../../samples/sample_433.md)  
[Pocket PC: base class](../../samples/sample_440.md)  
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  

## Declaration:
```foxpro  
HLOCAL LocalFree(
  HLOCAL hMem   //handle to local memory object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LocalFree IN kernel32;
	INTEGER hMem  
```  
***  


## Parameters:
hMem 
[in] Handle to the local memory object. This handle is returned by either the LocalAlloc or LocalReAlloc function.   
***  


## Return value:
If the function succeeds, the return value is NULL. If the function fails, the return value is equal to a handle to the local memory object.   
***  

