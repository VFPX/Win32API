[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetOpenFileName
Group: [Common Dialog Box](../../functions_group.md#Common_Dialog_Box)  -  Library: [comdlg32](../../Libraries.md#comdlg32)  
***  


#### The GetOpenFileName function creates an Open dialog box that lets the user specify the drive, directory, and the name of a file or set of files to open.
***  


## Code examples:
[Creating the Open dialog box to specify the drive, directory, and name of a file to open](../../samples/sample_363.md)  

## Declaration:
```foxpro  
BOOL GetOpenFileName(
	LPOPENFILENAME lpofn
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetOpenFileName IN comdlg32;
	STRING @ lpofn  
```  
***  


## Parameters:
lpofn
[in, out] Pointer to an OPENFILENAME structure that contains information used to initialize the dialog box. When GetOpenFileName returns, this structure contains information about the user"s file selection.   
***  


## Return value:
If the user specifies a file name and clicks the OK button, the return value is nonzero.  
***  


## Comments:
The GetFileNameFromBrowse provides similar functionality.  
  
![](../../images/getopenfilename.png)  

***  

