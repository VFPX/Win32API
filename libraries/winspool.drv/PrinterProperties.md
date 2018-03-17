<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : PrinterProperties
Group: Printing and Print Spooler - Library: winspool.drv    
***  


#### The PrinterProperties function displays a printer-properties property sheet for the specified printer. 
***  


## Code examples:
[Displaying printer-properties Property Sheet for the specified printer](../../samples/sample_372.md)  

## Declaration:
```foxpro  
BOOL PrinterProperties(
  HWND hWnd,        // handle to parent window
  HANDLE hPrinter   // handle to printer object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PrinterProperties IN winspool.drv;
	INTEGER hWnd,;
	INTEGER hPrinter
  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the parent window of the property sheet.

hPrinter
[in] Handle to a printer object. Use the OpenPrinter or AddPrinter function to retrieve a printer handle.
  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
Windows 95/98/Me: The PrinterProperties and DocumentProperties functions both display the same property sheet, which includes pages for setting document properties and printer properties.  
  
***  

