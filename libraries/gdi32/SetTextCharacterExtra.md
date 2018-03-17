<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetTextCharacterExtra
Group: Font and Text - Library: gdi32    
***  


#### The SetTextCharacterExtra function sets the intercharacter spacing. Intercharacter spacing is added to each character, including break characters, when the system writes a line of text. 
***  


## Code examples:
[Using Font and Text functions](../../samples/sample_304.md)  

## Declaration:
```foxpro  
int SetTextCharacterExtra(
  HDC hdc,         // handle to DC
  int nCharExtra   // extra-space value
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetTextCharacterExtra IN gdi32;
	INTEGER hdc,;
	INTEGER nCharExtra  
```  
***  


## Parameters:
```txt  
hdc
[in] Handle to the device context.

nCharExtra
[in] Specifies the amount of extra space, in logical units, to be added to each character.  
```  
***  


## Return value:
If the function succeeds, the return value is the previous intercharacter spacing. If the function fails, the return value is 0x80000000. 
  
***  

