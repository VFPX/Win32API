<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GlobalMemoryStatus
Group: Memory Management - Library: kernel32    
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
```txt  
lpBuffer
[out] Pointer to a MEMORYSTATUS structure. The GlobalMemoryStatus function stores information about current memory availability into this structure  
```  
***  


## Return value:
This function does not return a value  
***  


## Comments:
On computers with more than 4 GB of memory, the MEMORYSTATUS structure can return incorrect information.  
  
***  

