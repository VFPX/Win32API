[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetNearestColor
Group: [Color](../../functions_group.md#Color)  -  Library: [gdi32](../../Libraries.md#gdi32)  
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
hdc
Identifies the device context. 

crColor
Specifies a color value that identifies a requested color  
***  


## Return value:
If the function succeeds, the return value identifies a color from the system palette that corresponds to the given color value  
***  

