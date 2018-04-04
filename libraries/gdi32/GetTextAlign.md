[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTextAlign
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetTextAlign function retrieves the text-alignment setting for the specified device context.
***  


## Code examples:
[Using Font and Text functions](../../samples/sample_304.md)  

## Declaration:
```foxpro  
UINT GetTextAlign(
  HDC hdc   // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTextAlign IN gdi32;
	INTEGER hdc  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context.   
***  


## Return value:
If the function succeeds, the return value is the status of the text-alignment flags.  
***  

