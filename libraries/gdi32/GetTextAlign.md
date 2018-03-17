<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetTextAlign
Group: Font and Text - Library: gdi32    
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
```txt  
hdc
[in] Handle to the device context.  
```  
***  


## Return value:
If the function succeeds, the return value is the status of the text-alignment flags.  
***  

