<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetPrinterData
Group: Printing and Print Spooler - Library: winspool.drv    
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
```txt  
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
```  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  

