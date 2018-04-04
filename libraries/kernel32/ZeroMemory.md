[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ZeroMemory
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Fills a block of memory with zeros.
***  


## Code examples:
[How to print a bitmap file](../../samples/sample_211.md)  
[Vertical Label control](../../samples/sample_398.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  

## Declaration:
```foxpro  
VOID ZeroMemory(
  PVOID Destination,  // memory block
  SIZE_T Length       // size of memory block
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE RtlZeroMemory IN kernel32 As ZeroMemory;
	INTEGER dest,;
	INTEGER numBytes
  
```  
***  


## Parameters:
Destination 
[in] Pointer to the starting address of the block of memory to fill with zeros. 

Length 
[in] Size, in bytes, of the block of memory to fill with zeros.  
***  


## Return value:
This function has no return value.  
***  

