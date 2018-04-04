[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CommDlgExtendedError
Group: [Common Dialog Box](../../functions_group.md#Common_Dialog_Box)  -  Library: [comdlg32](../../Libraries.md#comdlg32)  
***  


#### The CommDlgExtendedError function returns a common dialog box error code. This code indicates the most recent error to occur during the execution of one of the common dialog box functions. 
***  


## Code examples:
[Creating the Save dialog box to specify the drive, directory, and name of a file to save](../../samples/sample_265.md)  
[Creating the Open dialog box to specify the drive, directory, and name of a file to open](../../samples/sample_363.md)  

## Declaration:
```foxpro  
DWORD CommDlgExtendedError(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CommDlgExtendedError IN comdlg32  
```  
***  


## Parameters:
This function has no parameters.   
***  


## Return value:
If the most recent call to a common dialog box function succeeded, the return value is undefined. 

If the common dialog box function returned FALSE because the user closed or canceled the dialog box, the return value is zero. Otherwise, the return value is a nonzero error code. 
  
***  

