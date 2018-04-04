[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTextFace
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetTextFace function retrieves the typeface name of the font that is selected into the specified device context. 
***  


## Code examples:
[Using Font and Text functions](../../samples/sample_304.md)  

## Declaration:
```foxpro  
int GetTextFace(
  HDC hdc,            // handle to DC
  int nCount,         // length of typeface name buffer
  LPTSTR lpFaceName   // typeface name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTextFace IN gdi32;
	INTEGER   hdc,;
	INTEGER   nCount,;
	STRING  @ lpFaceName  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

nCount 
[in] Specifies the length of the buffer pointed to by lpFaceName.

lpFaceName 
[out] Pointer to the buffer that receives the typeface name.   
***  


## Return value:
If the function succeeds, the return value is the number of characters copied to the buffer. If the function fails, the return value is zero.
  
***  

