<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ZeroMemory
Group: Memory Management - Library: kernel32    
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
```txt  
Destination
[in] Pointer to the starting address of the block of memory to fill with zeros.

Length
[in] Size, in bytes, of the block of memory to fill with zeros.  
```  
***  


## Return value:
This function has no return value.  
***  

