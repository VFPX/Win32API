<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeGlobalMemoryStatus
Group: Remote Application Programming (RAPI) - Library: rapi    
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
```txt  
lpmst
[out] Pointer to a MEMORYSTATUS structure.  
```  
***  


## Return value:
None.  
***  


## Comments:
Total and available physical memory, memory utilization, paging file...  
  
See also CeGetStoreInformation function.  
  
***  

