
## Function name : GdiFlush
Group: Painting and Drawing - Library: gdi32    
***  


#### Flushes the calling thread`s current batch.
***  


## Declaration:
```foxpro  
BOOL GdiFlush(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdiFlush IN gdi32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
If all functions in the current batch succeed, the return value is nonzero.

If not all functions in the current batch succeed, the return value is zero, indicating that at least one function returned an error.
  
***  


## Comments:
Batching enhances drawing performance by minimizing the amount of time needed to call GDI drawing functions that return Boolean values. The batch limit is maintained for each thread separately.  
  
See also: GdiGetBatchLimit, GdiSetBatchLimit   
  
***  

