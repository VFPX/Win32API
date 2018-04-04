[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeGetSystemInfo
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function returns information about the current system. 
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  

## Declaration:
```foxpro  
VOID CeGetSystemInfo(
  LPSYSTEM_INFO lpSystemInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE CeGetSystemInfo IN rapi;
	STRING @ lpSystemInfo  
```  
***  


## Parameters:
lpSystemInfo 
[out] Pointer to a SYSTEM_INFO structure to be filled in by this function.   
***  


## Return value:
None.  
***  


## Comments:
CPU architechture, type, level, revision, number of CPUs; virtual memory settings...  
  
***  

