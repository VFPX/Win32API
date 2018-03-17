<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetTextColor
Group: Font and Text - Library: gdi32    
***  


#### The GetTextColor function retrieves the current text color for the specified device context.
***  


## Code examples:
[Using Font and Text functions](../../samples/sample_304.md)  

## Declaration:
```foxpro  
COLORREF GetTextColor(
  HDC hdc   // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTextColor IN gdi32;
	INTEGER hdc  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context.  
```  
***  


## Return value:
If the function succeeds, the return value is the current text color as a COLORREF value. If the function fails, the return value is CLR_INVALID.
  
***  

