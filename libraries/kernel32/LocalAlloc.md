[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LocalAlloc
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The LocalAlloc function allocates the specified number of bytes from the heap.
***  


## Code examples:
[Creating a folder](../../samples/sample_001.md)  
[Retrieving local computer and user names](../../samples/sample_041.md)  
[Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)](../../samples/sample_360.md)  
[Pocket PC: base class](../../samples/sample_440.md)  
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  

## Declaration:
```foxpro  
HLOCAL LocalAlloc(
  UINT uFlags,
  SIZE_T uBytes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LocalAlloc IN kernel32;
	INTEGER uFlags,;
	INTEGER uBytes
  
```  
***  


## Parameters:
uFlags 
[in] Memory allocation attributes. 

uBytes 
[in] Number of bytes to allocate.  
***  


## Return value:
If the function succeeds, the return value is a handle to the newly allocated memory object.  
***  


## Comments:
Windows memory management does not provide a separate local heap and global heap.  
  
***  

