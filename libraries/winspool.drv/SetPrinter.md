[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetPrinter
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The SetPrinter function sets the data for a specified printer or sets the state of the specified printer by pausing printing, resuming printing, or clearing all print jobs. 
***  


## Code examples:
[How to delete all print jobs for a printer](../../samples/sample_370.md)  

## Declaration:
```foxpro  
BOOL SetPrinter(
  HANDLE hPrinter,  // handle to printer object
  DWORD Level,      // information level
  LPBYTE pPrinter,  // printer data buffer
  DWORD Command     // printer-state command
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetPrinter IN winspool.drv;
	INTEGER hPrinter,;
	INTEGER lvl,;
	INTEGER pPrinter,;
	INTEGER cmd
  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer. Use the OpenPrinter or AddPrinter function to retrieve a printer handle. 

Level 
[in] Specifies the type of data that the function stores into the buffer pointed to by pPrinter. If the Command parameter is not equal to zero, the Level parameter must be zero.

pPrinter 
[in] Pointer to a buffer containing data to set for the printer, or containing information for the command specified by the Command parameter.

Command 
[in] Specifies the action performed by the SetPrinter function.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
To modify the current printer settings, call the GetPrinter function to retrieve the current settings into a PRINTER_INFO_2 structure, modify the members of that structure as necessary, and then call SetPrinter.   
  
If you use SetPrinter to modify the default DEVMODE structure for a printer (globally setting the printer defaults), you must first call the DocumentProperties function to validate the DEVMODE structure.  
  
***  

