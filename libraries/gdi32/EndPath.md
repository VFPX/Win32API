[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EndPath
Group: [Path](../../functions_group.md#Path)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The EndPath function closes a path bracket and selects the path defined by the bracket into the specified device context.
***  


## Code examples:
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  

## Declaration:
```foxpro  
BOOL EndPath(
  HDC hdc   // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EndPath IN gdi32;
	INTEGER hdc  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context into which the new path is selected.  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
By calling this function an application closes an open path bracket started with BeginPath function.  
  
***  

