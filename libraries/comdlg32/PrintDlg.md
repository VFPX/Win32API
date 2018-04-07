[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PrintDlg
Group: [Common Dialog Box](../../functions_group.md#Common_Dialog_Box)  -  Library: [comdlg32](../../Libraries.md#comdlg32)  
***  


#### Displays a Print dialog box. The Print dialog box enables the user to specify the properties of a particular print job.
***  


## Code examples:
[Retrieving Printer Device Context using PrintDlg function](../../samples/sample_150.md)  
[Retrieving graphic capabilities of default printer](../../samples/sample_155.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[GDI+: printing image file](../../samples/sample_452.md)  
[GDI+: sending image of FoxPro form to printer](../../samples/sample_455.md)  

## Declaration:
```foxpro  
BOOL PrintDlg(
  LPPRINTDLG lppd   // initialization data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PrintDlg IN comdlg32;
	STRING @ lppd  
```  
***  


## Parameters:
lppd 
[in/out] Pointer to a PRINTDLG structure that contains information used to initialize the dialog box. When PrintDlg returns, this structure contains information about the user"s selections.  
***  


## Return value:
If the user clicks the OK button, the return value is nonzero. The members of the PRINTDLG structure pointed to by the lppd parameter indicate the user"s selections.  
***  


## Comments:
This function can be used to get a device context for a printer.  
  
See also: [PrintDlgEx](../comdlg32/PrintDlgEx.md), [DocumentProperties](../winspool.drv/DocumentProperties.md).  
  
***  

