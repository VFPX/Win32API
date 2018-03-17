<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdiplusShutdown
Group: GDI+ - Library: gdiplus    
***  


#### The GdiplusShutdown function cleans up resources used by Microsoft® Windows® GDI+.
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
```txt  
token
[in] Token returned by a previous call to GdiplusStartup.  
```  
***  


## Return value:
No return value.  
***  


## Comments:
Each call to GdiplusStartup should be paired with a call to GdiplusShutdown.  
  
You must call GdiplusStartup before you create any GDI+ objects, and you must delete all of your GDI+ objects (or have them go out of scope) before you call GdiplusShutdown.  
  
***  

