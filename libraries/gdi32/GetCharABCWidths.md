[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCharABCWidths
Group: [Font and Text](../../functions_group.md#Font_and_Text)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### Retrieves the widths, in logical units, of consecutive characters in a specified range from the current TrueType font. This function succeeds only with TrueType fonts.
***  


## Declaration:
```foxpro  
BOOL GetCharABCWidths(
  HDC hdc,         // handle to DC
  UINT uFirstChar, // first character in range
  UINT uLastChar,  // last character in range
  LPABC lpabc      // array of character widths
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCharABCWidths IN gdi32;
	INTEGER   hdc,;
	INTEGER   uFirstChar,;
	INTEGER   uLastChar,;
	STRING  @ lpabc
  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context. 

uFirstChar 
[in] Specifies the first character in the group of consecutive characters from the current font. 

uLastChar 
[in] Specifies the last character in the group of consecutive characters from the current font. 

lpabc 
[out] Pointer to an array of ABC structures that receives the character widths, in logical units.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
MSDN: To retrieve the widths of characters in non-TrueType fonts, applications should use the GetCharWidth function.  
  
***  

