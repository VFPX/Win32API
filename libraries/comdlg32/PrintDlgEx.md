<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PrintDlgEx
Group: Common Dialog Box - Library: comdlg32    
***  


#### The PrintDlgEx function displays a Print property sheet that enables the user to specify the properties of a particular print job.
***  


## Code examples:
[How to display the Print property sheet](../../samples/sample_531.md)  

## Declaration:
```foxpro  
HRESULT PrintDlgEx(
	LPPRINTDLGEX lppd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PrintDlgEx IN comdlg32;
	STRING @lppd  
```  
***  


## Parameters:
```txt  
lppd
[in, out] Pointer to a PRINTDLGEX structure that contains information used to initialize the property sheet.  
```  
***  


## Return value:
If the function succeeds, the return value is S_OK (0).  
***  


## Comments:
The Print property sheet has the General page with controls similar to the Print dialog box.   
  
<img src="images/print_property_sheet.png" width=493 height=446>  
  
The property sheet can also have additional application-specific and driver-specific property pages following the General page.  
  
When the PrintDlgEx returns, the PRINTDLGEX structure contains information about the user`s selections.   
  
On successful return the dwResultAction member of the PRINTDLGEX structure contains one of the following values: PD_RESULT_APPLY, PD_RESULT_CANCEL, PD_RESULT_PRINT.  
  
See also: PrintDlg, DocumentProperties   
  
***  

