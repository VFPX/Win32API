[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ChooseFont
Group: [Common Dialog Box](../../functions_group.md#Common_Dialog_Box)  -  Library: [comdlg32](../../Libraries.md#comdlg32)  
***  


#### Creates a Font dialog box that enables the user to choose attributes for a logical font. These attributes include a typeface name, style (bold, italic, or regular), point size, effects (underline, strikeout, and text color), and a script (or character set).
***  


## Code examples:
[Enhanced GetFont dialog](../../samples/sample_159.md)  

## Declaration:
```foxpro  
BOOL ChooseFont(
  LPCHOOSEFONT lpcf  //initialization data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ChooseFont IN comdlg32;
	STRING @lpcf  
```  
***  


## Parameters:
lpcf 
[in/out] Pointer to a CHOOSEFONT structure that contains information used to initialize the dialog box.  
***  


## Return value:
If the user clicks the OK button of the dialog box, the return value is nonzero.  
***  

