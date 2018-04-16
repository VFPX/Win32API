[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeGlobalMemoryStatus
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function gets information on the physical and virtual memory of the system.
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  

## Declaration:
```foxpro  
void CeGlobalMemoryStatus(
  LPMEMORYSTATUS lpmst
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE CeGlobalMemoryStatus IN rapi;
	STRING @ lpmst  
```  
***  


## Parameters:
lpmst 
[out] Pointer to a MEMORYSTATUS structure.  
***  


## Return value:
None.  
***  


## Comments:
Total and available physical memory, memory utilization, paging file...  
  
See also: [CeGetStoreInformation](CeGetStoreInformation.md) function.  
  
***  

