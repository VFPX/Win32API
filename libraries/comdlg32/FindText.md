<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindText
Group: Common Dialog Box - Library: comdlg32    
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
```txt  
lpfr
[in] Pointer to a FINDREPLACE structure that contains information used to initialize the dialog box.  
```  
***  


## Return value:
If the function succeeds, the return value is the window handle to the dialog box.  
***  

