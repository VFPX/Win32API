[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GlobalMemoryStatus
Group: [Memory Management](../../functions_group.md#Memory_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GlobalMemoryStatus function obtains information about the system"s current usage of both physical and virtual memory.

***  


## Code examples:
[Displaying OS Memory Status](../../samples/sample_020.md)  

## Declaration:
```foxpro  
VOID GlobalMemoryStatus(
  LPMEMORYSTATUS lpBuffer   // memory status structure
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GlobalMemoryStatus IN kernel32 STRING @ lpBuffer
  
```  
***  


## Parameters:
lpBuffer 
[out] Pointer to a MEMORYSTATUS structure. The GlobalMemoryStatus function stores information about current memory availability into this structure  
***  


## Return value:
This function does not return a value  
***  


## Comments:
On computers with more than 4 GB of memory, the MEMORYSTATUS structure can return incorrect information.  
  
***  

