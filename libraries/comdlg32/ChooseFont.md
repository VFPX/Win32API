<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ChooseFont
Group: Common Dialog Box - Library: comdlg32    
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
```txt  
lpcf
[in/out] Pointer to a CHOOSEFONT structure that contains information used to initialize the dialog box.  
```  
***  


## Return value:
If the user clicks the OK button of the dialog box, the return value is nonzero.  
***  

