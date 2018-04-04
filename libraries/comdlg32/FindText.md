[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindText
Group: [Common Dialog Box](../../functions_group.md#Common_Dialog_Box)  -  Library: [comdlg32](../../Libraries.md#comdlg32)  
***  


#### Creates a system-defined modeless Find dialog box that lets the user specify a string to search for and options to use when searching for text in a document.
***  


## Code examples:
[FindText -- the hopeless and useless Common Dialog](../../samples/sample_160.md)  

## Declaration:
```foxpro  
HWND FindText(
  LPFINDREPLACE lpfr   // initialization data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindText IN comdlg32;
	STRING @ lpfr  
```  
***  


## Parameters:
lpfr 
[in] Pointer to a FINDREPLACE structure that contains information used to initialize the dialog box.  
***  


## Return value:
If the function succeeds, the return value is the window handle to the dialog box.  
***  

