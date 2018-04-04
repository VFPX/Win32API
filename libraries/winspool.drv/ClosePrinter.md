[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ClosePrinter
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The ClosePrinter function closes the specified printer object. 
***  


## Code examples:
[Adding printer to the list of supported printers for the specified server](../../samples/sample_335.md)  
[Retrieving default spooling directory name](../../samples/sample_358.md)  
[Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)](../../samples/sample_360.md)  
[How to retrieve the number of print jobs queued for the printer](../../samples/sample_367.md)  
[Enumerating print jobs and retrieving information for default printer (JOB_INFO_1 structures)](../../samples/sample_368.md)  
[How to retrieve configuration data for a specified printer stored in the registry (PrinterDriverData key)](../../samples/sample_369.md)  
[How to delete all print jobs for a printer](../../samples/sample_370.md)  
[Displaying printer-properties Property Sheet for the specified printer](../../samples/sample_372.md)  
[Simple printer queue monitor: deletes, pauses, resumes print jobs for local printer](../../samples/sample_373.md)  
[How to browse and connect to printers on a network (WinNT)](../../samples/sample_376.md)  
[Configuring DEVMODE structure for a printer](../../samples/sample_384.md)  
[Enumerating forms supported by a specified printer](../../samples/sample_390.md)  
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  

## Declaration:
```foxpro  
BOOL ClosePrinter(
  HANDLE hPrinter   // handle to printer object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ClosePrinter IN winspool.drv;
	INTEGER hPrinter  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer object to be closed. This handle is returned by the OpenPrinter or AddPrinter function.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
When the ClosePrinter function returns, the handle hPrinter is invalid, regardless of whether the function has succeeded or failed.  
  
***  

