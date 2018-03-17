<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetBkMode
Group: Painting and Drawing - Library: gdi32    
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
```txt  
hdc
[in] Handle to the device context whose background mode is to be returned.  
```  
***  


## Return value:
If the function succeeds, the return value specifies the current background mix mode, either OPAQUE or TRANSPARENT. 

If the function fails, the return value is zero. 
  
***  


## Comments:
#DEFINE OPAQUE       2  
#DEFINE TRANSPARENT  1  
  
***  

