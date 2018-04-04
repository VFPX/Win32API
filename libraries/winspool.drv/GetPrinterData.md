[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPrinterData
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The GetPrinterData function retrieves configuration data for the specified printer or print server. 
***  


## Code examples:
[Retrieving default spooling directory name](../../samples/sample_358.md)  

## Declaration:
```foxpro  
DWORD GetPrinterData(
  HANDLE hPrinter,    // handle to printer or print server
  LPTSTR pValueName,  // value name
  LPDWORD pType,      // data type
  LPBYTE pData,       // configuration data buffer
  DWORD nSize,        // size of configuration data buffer
  LPDWORD pcbNeeded   // bytes received or required
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPrinterData IN winspool.drv;
	INTEGER   hPrinter,;
	STRING    pValueName,;
	INTEGER @ pType,;
	STRING  @ pData,;
	INTEGER   nSize,;
	INTEGER @ pcbNeeded  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer or print server for which the function retrieves configuration data. Use the OpenPrinter or AddPrinter function to retrieve a printer handle. 

pValueName 
[in] Pointer to a null-terminated string that identifies the data to retrieve.

pType 
[out] Pointer to a variable that receives the type of data retrieved.

pData 
[out] Pointer to a buffer that receives the configuration data. 

nSize 
[in] Specifies the size, in bytes, of the buffer pointed to by pData. 

pcbNeeded 
[out] Pointer to a variable that receives the size, in bytes, of the configuration data.   
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  

