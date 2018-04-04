[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSysColor
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the current color of the specified display element. Display elements are the parts of a window and the Windows display that appear on the system display screen
***  


## Code examples:
[Using GetSysColor](../../samples/sample_039.md)  
[Changing system colors](../../samples/sample_040.md)  

## Declaration:
```foxpro  
DWORD GetSysColor(
	int  nIndex 	// display element
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSysColor IN user32 INTEGER nIndex  
```  
***  


## Parameters:
nIndex
Specifies the display element whose color is to be retrieved  
***  


## Return value:
If the function succeeds, the return value is the red, green, blue (RGB) color value that specifies the color of the given element  
***  


## Comments:
Some constants are not availble for Win9 or otherwise for WinNT. The "reverse" function is SetSysColors. Note the difference: GetSysColor restores one color at a time; SetSysColors function allows to change several colors at once  
  
***  

