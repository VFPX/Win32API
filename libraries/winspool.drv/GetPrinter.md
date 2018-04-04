[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPrinter
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The GetPrinter function retrieves information about a specified printer. 
***  


## Code examples:
[Retrieving the name of the default printer for the current user on the local computer (Win NT/XP)](../../samples/sample_360.md)  
[How to retrieve the number of print jobs queued for the printer](../../samples/sample_367.md)  
[How to browse and connect to printers on a network (WinNT)](../../samples/sample_376.md)  

## Declaration:
```foxpro  
BOOL GetPrinter(
  HANDLE hPrinter,    // handle to printer
  DWORD Level,        // information level
  LPBYTE *pPrinter,    // printer information buffer
  DWORD cbBuf,        // size of buffer
  LPDWORD pcbNeeded   // bytes received or required
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPrinter IN winspool.drv;
AS GetPrinterA;
	INTEGER   hPrinter,;
	INTEGER   Lvl,;
	STRING  @ pPrinter,;
	INTEGER   cbBuf,;
	INTEGER @ pcbNeeded  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer for which the function retrieves information. Use the OpenPrinter or AddPrinter function to retrieve a printer handle. 

Level 
[in] Specifies the level or type of structure that the function stores into the buffer pointed to by pPrinter.

pPrinter 
[out] Pointer to a buffer that receives a structure containing information about the specified printer.

cbBuf 
[in] Specifies the size, in bytes, of the buffer pointed to by pPrinter. 

pcbNeeded 
[out] Pointer to a variable that the function sets to the size, in bytes, of the printer information.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
Corresponding FoxPro functions: GetPrinter(), SYS(1037).  
  
***  

