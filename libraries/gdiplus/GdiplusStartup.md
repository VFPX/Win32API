[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdiplusStartup
Group: [GDI+](../../functions_group.md#GDIplus)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### The GdiplusStartup function initializes Microsoft&reg; Windows&reg; GDI+.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
Status GdiplusStartup(          ULONG_PTR token *token,
    const GdiplusStartupInput *input,
    GdiplusStartupOutput *output
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdiplusStartup IN gdiplus;
	INTEGER @ token,;
	STRING  @ input,;
	INTEGER   output
  
```  
***  


## Parameters:
token
[out] Pointer to a ULONG_PTR that receives a token. Pass the token to GdiplusShutdown when you have finished using GDI+. 

input
[in] Pointer to a GdiplusStartupInput structure.

output
[out] Pointer to a GdiplusStartupOutput structure.  
***  


## Return value:
If the function succeeds, it returns Ok (0), which is an element of the Status enumeration.  
***  


## Comments:
Call GdiplusStartup before making any other GDI+ calls, and call GdiplusShutdown when you have finished using GDI+.  
  
You must call GdiplusStartup before you create any GDI+ objects, and you must delete all of your GDI+ objects (or have them go out of scope) before you call GdiplusShutdown.  
  
***  

