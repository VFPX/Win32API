<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdiGetBatchLimit
Group: Painting and Drawing - Library: gdi32    
***  


#### Returns the maximum number of function calls that can be accumulated in the calling thread`s current batch. 
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
```txt  
This function has no parameters.   
```  
***  


## Return value:
If the function succeeds, the return value is the batch limit. If the function fails, the return value is zero. 
  
***  


## Comments:
The batch limit is set by using the GdiSetBatchLimit function. Setting the limit to 1 effectively disables batching.  
  
See also: GdiSetBatchLimit, GdiFlush   
  
***  

