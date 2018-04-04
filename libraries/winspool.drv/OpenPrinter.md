[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenPrinter
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The OpenPrinter function retrieves a handle to the specified printer or print server or other types of handles in the print subsystem.
***  


## Code examples:
[Retrieving default spooling directory name](../../samples/sample_358.md)  
[Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)](../../samples/sample_360.md)  
[How to retrieve the number of print jobs queued for the printer](../../samples/sample_367.md)  
[Enumerating print jobs and retrieving information for default printer (JOB_INFO_1 structures)](../../samples/sample_368.md)  
[How to retrieve configuration data for a specified printer stored in the registry (PrinterDriverData key)](../../samples/sample_369.md)  
[How to delete all print jobs for a printer](../../samples/sample_370.md)  
[Displaying printer-properties Property Sheet for the specified printer](../../samples/sample_372.md)  
[Simple printer queue monitor: deletes, pauses, resumes print jobs for local printer](../../samples/sample_373.md)  
[Configuring DEVMODE structure for a printer](../../samples/sample_384.md)  
[Enumerating forms supported by a specified printer](../../samples/sample_390.md)  
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  

## Declaration:
```foxpro  
BOOL OpenPrinter(
  LPTSTR pPrinterName,         // printer or server name
  LPHANDLE phPrinter,          // printer or server handle
  LPPRINTER_DEFAULTS pDefault  // printer defaults
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenPrinter IN winspool.drv;
	STRING    pPrinterName,;
	INTEGER @ phPrinter,;
	INTEGER   pDefault  
```  
***  


## Parameters:
pPrinterName 
[in] Pointer to a null-terminated string that specifies the name of the printer or print server, the printer object, the XcvMonitor, or the XcvPort. 

phPrinter 
[out] Pointer to a variable that receives a handle to the open printer or print server object.

pDefault 
[in] Pointer to a PRINTER_DEFAULTS structure. This value can be NULL.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

