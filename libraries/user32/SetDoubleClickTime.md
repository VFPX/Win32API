[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetDoubleClickTime
Group: [Mouse Input](../../functions_group.md#Mouse_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Sets the double-click time for the mouse
***  


## Code examples:
[Setting and retrieving the double-click time for the mouse](../../samples/sample_054.md)  

## Declaration:
```foxpro  
BOOL SetDoubleClickTime(
  UINT uInterval   // double-click interval
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetDoubleClickTime IN user32 INTEGER wCount  
```  
***  


## Parameters:
uInterval 
[in] Specifies the number of milliseconds that may occur between the first and second clicks  
***  


## Return value:
If the function succeeds, the return value is nonzero  
***  


## Comments:
Regular value for the DoubleClick time is 500 milliseconds. By setting this parameter to, say, 50 millisecond you can virtually disable the double click, because none can do it in such a short time.  
  
***  

