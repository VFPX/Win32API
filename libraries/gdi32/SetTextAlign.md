[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetTextAlign
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The SetTextAlign function sets the text-alignment flags for the specified device context. 
***  


## Code examples:
[Using Font and Text functions](../../samples/sample_304.md)  

## Declaration:
```foxpro  
UINT SetTextAlign(
  HDC hdc,     // handle to DC
  UINT fMode   // text-alignment option
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetTextAlign IN gdi32;
	INTEGER hdc,;
	INTEGER fMode  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

fMode 
[in] Specifies the text alignment by using a mask of the values in the following list.   
***  


## Return value:
If the function succeeds, the return value is the previous text-alignment setting.  
***  

