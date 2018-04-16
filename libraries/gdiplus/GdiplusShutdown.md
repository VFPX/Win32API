[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdiplusShutdown
Group: [GDI+](../../functions_group.md#GDIplus)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### The GdiplusShutdown function cleans up resources used by Microsoft&reg; Windows&reg; GDI+.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
void GdiplusShutdown(
    ULONG_PTR token
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GdiplusShutdown IN gdiplus;
	INTEGER token  
```  
***  


## Parameters:
token
[in] Token returned by a previous call to GdiplusStartup.   
***  


## Return value:
No return value.  
***  


## Comments:
Each call to GdiplusStartup should be paired with a call to GdiplusShutdown.  
  
You must call GdiplusStartup before you create any GDI+ objects, and you must delete all of your GDI+ objects (or have them go out of scope) before you call GdiplusShutdown.  
  
***  

