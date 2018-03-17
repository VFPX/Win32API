<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetSaveFileName
Group: Common Dialog Box - Library: comdlg32    
***  


#### The GetSaveFileName function creates a Save dialog box that lets the user specify the drive, directory, and name of a file to save.
***  


## Code examples:
[Creating the Save dialog box to specify the drive, directory, and name of a file to save](../../samples/sample_265.md)  

## Declaration:
```foxpro  
BOOL GetSaveFileName(
  LPOPENFILENAME lpofn   // initialization data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSaveFileName IN comdlg32;
	STRING @lpofn  
```  
***  


## Parameters:
```txt  
lpofn
[in/out] Pointer to an OPENFILENAME structure that contains information used to initialize the dialog box.  
```  
***  


## Return value:
If the user specifies a file name and clicks the OK button and the function is successful, the return value is nonzero.   
***  

