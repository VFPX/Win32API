<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetTextCharacterExtra
Group: Font and Text - Library: gdi32    
***  


#### The GetTextCharacterExtra function retrieves the current intercharacter spacing for the specified device context. 
***  


## Code examples:
[Using Font and Text functions](../../samples/sample_304.md)  

## Declaration:
```foxpro  
int GetTextCharacterExtra(
  HDC hdc   // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTextCharacterExtra IN gdi32;
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
If the function succeeds, the return value is the current intercharacter spacing, in logical coordinates. If the function fails, the return value is 0x8000000. 
  
***  

