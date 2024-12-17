[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdiGetBatchLimit
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Returns the maximum number of function calls that can be accumulated in the calling thread's current batch. 
***  


## Declaration:
```foxpro  
DWORD GdiGetBatchLimit(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG GdiGetBatchLimit IN gdi32  
```  
***  


## Parameters:
This function has no parameters.   
***  


## Return value:
If the function succeeds, the return value is the batch limit. If the function fails, the return value is zero. 
  
***  


## Comments:
The batch limit is set by using the GdiSetBatchLimit function. Setting the limit to 1 effectively disables batching.  
  
See also: [GdiSetBatchLimit](../gdi32/GdiSetBatchLimit.md), [GdiFlush](../gdi32/GdiFlush.md).  
  
***  

