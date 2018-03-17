<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FillMemory
Group: Memory Management - Library: kernel32    
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
```txt  
Destination
[out] Pointer to the starting address of the block of memory to fill.

Length
[in] Specifies the size, in bytes, of the block of memory to fill.

Fill
[in] Specifies the byte value with which to fill the memory block.  
```  
***  


## Return value:
This function has no return value.   
***  

