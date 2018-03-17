<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeGetSystemInfo
Group: Remote Application Programming (RAPI) - Library: rapi    
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
```txt  
lpSystemInfo
[out] Pointer to a SYSTEM_INFO structure to be filled in by this function.  
```  
***  


## Return value:
None.  
***  


## Comments:
CPU architechture, type, level, revision, number of CPUs; virtual memory settings...  
  
***  

