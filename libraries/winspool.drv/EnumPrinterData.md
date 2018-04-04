[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumPrinterData
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The EnumPrinterData function enumerates configuration data for a specified printer. 
***  


## Code examples:
[How to retrieve configuration data for a specified printer stored in the registry (PrinterDriverData key)](../../samples/sample_369.md)  

## Declaration:
```foxpro  
DWORD EnumPrinterData(
  HANDLE hPrinter,       // handle to printer
  DWORD dwIndex,         // index of value to retrieve
  LPTSTR pValueName,     // value name buffer
  DWORD cbValueName,     // size of value name buffer
  LPDWORD pcbValueName,  // bytes received
  LPDWORD pType,         // value type code
  LPBYTE pData,          // value data buffer
  DWORD cbData,          // size of value data buffer
  LPDWORD pcbData        // bytes received
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumPrinterData IN winspool.drv;
	INTEGER   hPrinter,;
	INTEGER   dwIndex,;
	STRING  @ pValueName,;
	INTEGER   cbValueName,;
	INTEGER @ pcbValueName,;
	INTEGER @ pType,;
	STRING  @ pData,;
	INTEGER   cbData,;
	INTEGER @ pcbData
  
```  
***  


## Parameters:
hPrinter 
[in] Handle to the printer whose configuration data is to be obtained. 

dwIndex 
[in] An index value that specifies the configuration data value to retrieve. 

pValueName 
[out] Pointer to a buffer that receives the name of the configuration data value.

cbValueName 
[in] Specifies the size, in bytes, of the buffer pointed to by pValueName.

pcbValueName 
[out] Pointer to a variable that receives the number of bytes stored into the buffer pointed to by pValueName. 

pType 
[out] Pointer to a variable that receives a code indicating the type of data stored in the specified value.

pData 
[out] Pointer to a buffer that receives the configuration data value. 

cbData 
[in] Specifies the size, in bytes, of the buffer pointed to by pData.

pcbData 
[out] Pointer to a variable that receives the number of bytes stored into the buffer pointed to by pData.   
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
MSDN: EnumPrinterData retrieves printer configuration data set by the SetPrinterData function. A printer"s configuration data consists of a set of named and typed values. The EnumPrinterData function obtains one of these values, and its name and a type code, each time you call it. Call the EnumPrinterData function several times in succession to obtain all of a printer"s configuration data values.   
  
***  

