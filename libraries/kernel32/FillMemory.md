[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FillMemory
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FillMemory function fills a block of memory with a specified value.
***  


## Code examples:
[Using FillMemory](../../samples/sample_198.md)  

## Declaration:
```foxpro  
VOID FillMemory (
  PVOID Destination,  // memory block
  SIZE_T Length,      // size of memory block
  BYTE Fill           // fill value
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE RtlFillMemory IN kernel32 AS FillMemory;
	INTEGER Dest,;
	INTEGER Length,;
	SHORT   nFill
  
```  
***  


## Parameters:
Destination 
[out] Pointer to the starting address of the block of memory to fill. 

Length 
[in] Specifies the size, in bytes, of the block of memory to fill. 

Fill 
[in] Specifies the byte value with which to fill the memory block.   
***  


## Return value:
This function has no return value.   
***  

