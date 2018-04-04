[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WTSFreeMemory
Group: [Terminal Services](../../functions_group.md#Terminal_Services)  -  Library: [wtsapi32](../../Libraries.md#wtsapi32)  
***  


#### Frees memory allocated by a Terminal Services function.

***  


## Code examples:
[How to enumerate sessions and processes on a specified terminal server](../../samples/sample_519.md)  
[How to enumerate terminal servers within the specified Windows domain](../../samples/sample_520.md)  

## Declaration:
```foxpro  
void WTSFreeMemory(
	PVOID pMemory
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE WTSFreeMemory IN Wtsapi32;
	INTEGER pMemory  
```  
***  


## Parameters:
pMemory 
[in] Pointer to the memory to free.   
***  


## Return value:
This function does not return a value.  
***  


## Comments:
Several Terminal Services functions allocate buffers to return information. Use the WTSFreeMemory function to free these buffers.  
  
***  

