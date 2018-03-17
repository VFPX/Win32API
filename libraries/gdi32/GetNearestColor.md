<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetNearestColor
Group: Color - Library: gdi32    
***  


#### The GetNearestColor function returns a color value identifying a color from the system palette that will be displayed when the specified color value is used
***  


## Code examples:
[Using GetNearestColor](../../samples/sample_044.md)  

## Declaration:
```foxpro  
COLORREF GetNearestColor(
	HDC  hdc,	// handle of device context
	COLORREF  crColor 	// color to be matched
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetNearestColor IN "gdi32";
	INTEGER hdc,;
	INTEGER crColor  
```  
***  


## Parameters:
```txt  
hdc
Identifies the device context.

crColor
Specifies a color value that identifies a requested color  
```  
***  


## Return value:
If the function succeeds, the return value identifies a color from the system palette that corresponds to the given color value  
***  

