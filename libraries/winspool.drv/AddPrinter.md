[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AddPrinter
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
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
pName 
[in] Pointer to a null-terminated string that specifies the name of the server on which the printer should be installed.

Level 
[in] Specifies the version of the structure to which pPrinter points. This value must be 2. 

pPrinter 
[in] Pointer to a PRINTER_INFO_2 structure that contains information about the printer.  
***  


## Return value:
If the function succeeds, the return value is the handle to a new printer object.  
***  


## Comments:
When you are finished with the handle, pass it to the ClosePrinter function to close it.  
  
Use the EnumPrintProcessors function to enumerate the set of print processors installed on a server. Use the EnumPrintProcessorDatatypes function to enumerate the set of data types that a print processor supports. Use the EnumPorts function to enumerate the set of available ports. Use the EnumPrinterDrivers function to enumerate the installed printer drivers.  
  
***  

