[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LocalSize
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The LocalSize function returns the current size of the specified local memory object, in bytes.
***  


## Code examples:
[Retrieving local computer and user names](../../samples/sample_041.md)  
[Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)](../../samples/sample_360.md)  
[GetFileOwner - Get the owner of an NTFS file](../../samples/sample_433.md)  
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  

## Declaration:
```foxpro  
UINT LocalSize(
  HLOCAL hMem
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG LocalSize IN kernel32 INTEGER hMem  
```  
***  


## Parameters:
hMem 
[in] Handle to the local memory object. This handle is returned by the LocalAlloc, LocalReAlloc, or LocalHandle function.   
***  


## Return value:
If the function succeeds, the return value is the size of the specified local memory object, in bytes.  
***  


## Comments:
The local functions are slower than other memory management functions and do not provide as many features. Therefore, new applications should use the heap functions.  
  
***  

