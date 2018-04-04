[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumPrinters
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The EnumPrinters function enumerates available printers, print servers, domains, or print providers.
***  


## Code examples:
[Using EnumPrinters function to enumerate locally installed printers](../../samples/sample_146.md)  

## Declaration:
```foxpro  
BOOL EnumPrinters(
  DWORD Flags,         // printer object types
  LPTSTR Name,         // name of printer object
  DWORD Level,         // information level
  LPBYTE pPrinterEnum, // printer information buffer
  DWORD cbBuf,         // size of printer information buffer
  LPDWORD pcbNeeded,   // bytes received or required
  LPDWORD pcReturned   // number of printers enumerated
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumPrinters IN winspool.drv;
	INTEGER   Flags,;
	INTEGER   Name,;
	INTEGER   Level,;
	STRING  @ pPrinterEnum,;
	INTEGER   cbBuf,;
	INTEGER @ pcbNeeded,;
	INTEGER @ pcReturned  
```  
***  


## Parameters:
Flags 
[in] Specifies the types of print objects that the function should enumerate. 

Name
A pointer to a null-terminated string or NULL.

Level 
[in] Specifies the type of data structures pointed to by pPrinterEnum. Valid values are 1, 2, 4, and 5, which correspond to the PRINTER_INFO_1, PRINTER_INFO_2, PRINTER_INFO_4, and PRINTER_INFO_5 data structures. 

pPrinterEnum 
[out] Pointer to a buffer that receives an array of PRINTER_INFO_1, PRINTER_INFO_2, PRINTER_INFO_4, or PRINTER_INFO_5 structures. 

cbBuf 
[in] Specifies the size, in bytes, of the buffer pointed to by pPrinterEnum.

pcbNeeded 
[out] Pointer to a value that receives the number of bytes copied if the function succeeds or the number of bytes required if cbBuf is too small. 

pcReturned 
[out] Pointer to a value that receives the number of structures that the function returns in the array to which pPrinterEnum points.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value. If the function fails, the return value is zero. 
  
***  

