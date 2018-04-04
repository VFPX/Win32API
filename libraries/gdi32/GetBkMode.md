[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetBkMode
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Returns the current background mix mode for a specified device context. The background mix mode of a device context affects text, hatched brushes, and pen styles that are not solid lines.
***  


## Declaration:
```foxpro  
int GetBkMode(
  HDC hdc   // handle to device context
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetBkMode IN gdi32;
	INTEGER hdc
  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context whose background mode is to be returned.   
***  


## Return value:
If the function succeeds, the return value specifies the current background mix mode, either OPAQUE or TRANSPARENT. 

If the function fails, the return value is zero. 
  
***  


## Comments:
#DEFINE OPAQUE       2  
#DEFINE TRANSPARENT  1  
  
***  

