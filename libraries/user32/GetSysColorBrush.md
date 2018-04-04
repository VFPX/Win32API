[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSysColorBrush
Group: [Brush](../../functions_group.md#Brush)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves a handle identifying a logical brush that corresponds to the specified color index.
***  


## Code examples:
[Using FrameRgn for displaying system colors](../../samples/sample_125.md)  

## Declaration:
```foxpro  
HBRUSH GetSysColorBrush(
  int nIndex  // system color index
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSysColorBrush IN user32 INTEGER nIndex  
```  
***  


## Parameters:
nIndex 
[in] Specifies a color index. This value corresponds to the color used to paint one of the window elements.  
***  


## Return value:
The return value identifies a logical brush if the nIndex parameter is supported by the current platform. Otherwise, it returns NULL.  
***  


## Comments:
System color brushes are owned by the system and must not be destroyed. That means you should not apply DeleteObject to brushes returned by this function.  
  
***  

