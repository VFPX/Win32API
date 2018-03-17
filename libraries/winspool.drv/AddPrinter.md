<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : AddPrinter
Group: Printing and Print Spooler - Library: winspool.drv    
***  


#### The AddPrinter function adds a printer to the list of supported printers for a specified server. 
***  


## Code examples:
[Adding printer to the list of supported printers for the specified server](../../samples/sample_335.md)  

## Declaration:
```foxpro  
HANDLE AddPrinter(
  LPTSTR pName,     // server name
  DWORD Level,      // printer information level
  LPBYTE pPrinter   // printer information buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AddPrinter IN winspool.drv;
	STRING    pName,;
	INTEGER   Level,;
	STRING  @ pPrinter
  
```  
***  


## Parameters:
```txt  
pName
[in] Pointer to a null-terminated string that specifies the name of the server on which the printer should be installed.

Level
[in] Specifies the version of the structure to which pPrinter points. This value must be 2.

pPrinter
[in] Pointer to a PRINTER_INFO_2 structure that contains information about the printer.  
```  
***  


## Return value:
If the function succeeds, the return value is the handle to a new printer object.  
***  


## Comments:
When you are finished with the handle, pass it to the ClosePrinter function to close it.  
  
Use the EnumPrintProcessors function to enumerate the set of print processors installed on a server. Use the EnumPrintProcessorDatatypes function to enumerate the set of data types that a print processor supports. Use the EnumPorts function to enumerate the set of available ports. Use the EnumPrinterDrivers function to enumerate the installed printer drivers.  
  
***  

