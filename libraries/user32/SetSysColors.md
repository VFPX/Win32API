[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetSysColors
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Sets the colors for one or more display elements. Display elements are the various parts of a window and the Windows display that appear on the system display screen
***  


## Code examples:
[Changing system colors](../../samples/sample_040.md)  

## Declaration:
```foxpro  
BOOL WINAPI SetSysColors(
	int  cDspElements,	// number of elements to change
	CONST INT  *lpnDspElements,	// address of array of elements
	CONST COLORREF  *lpdwRgbValues 	// address of array of RGB values
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetSysColors IN user32;
	INTEGER nChanges,;
	INTEGER @ lpSysColor,;
	INTEGER @ lpColorValues  
```  
***  


## Parameters:
cDspElements
Specifies the number of display elements in the array pointed to by the lpnDspElements parameter. 

lpnDspElements
Points to an array of integers that specify the display elements to be changed. For a list of display elements, see the GetSysColor function.

lpdwRgbValues
Points to an array of unsigned long integers that contains the new red, green, blue (RGB) color value for each display element in the array pointed to by the lpnDspElements parameter.  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
As distinct from GetSysColor the SetSysColors can change several system colors at a time. It is important to pass the second and the third parameters by their references  
  
***  

