<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetBkColor
Group: Painting and Drawing - Library: gdi32    
***  


#### The SetBkColor function sets the current background color to the specified color value, or to the nearest physical color if the device cannot represent the specified color value. 
***  


## Code examples:
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[How to put a vertical text scrolling on the form (a movie cast)](../../samples/sample_354.md)  

## Declaration:
```foxpro  
COLORREF SetBkColor(
  HDC hdc,           // handle to DC
  COLORREF crColor   // background color value
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetBkColor IN gdi32;
	INTEGER hdc,;
	LONG    crColor  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context.

crColor
[in] Specifies the new background color.  
```  
***  


## Return value:
If the function succeeds, the return value specifies the previous background color as a COLORREF value. If the function fails, the return value is CLR_INVALID. 
  
***  

