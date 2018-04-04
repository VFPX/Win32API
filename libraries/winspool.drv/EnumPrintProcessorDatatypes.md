[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumPrintProcessorDatatypes
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The EnumPrintProcessorDatatypes function enumerates the data types that a specified print processor supports.
***  


## Code examples:
[Enumerating print processors and supporting data types installed on the specified server](../../samples/sample_333.md)  

## Declaration:
```foxpro  
BOOL EnumPrintProcessorDatatypes(
  LPTSTR pName,                // printer server name
  LPTSTR pPrintProcessorName,  // print processor name
  DWORD Level,                 // information level
  LPBYTE pDatatypes,           // processor data buffer
  DWORD cbBuf,                 // size of data buffer
  LPDWORD pcbNeeded,           // bytes received or required
  LPDWORD pcReturned           // number of processors
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumPrintProcessorDatatypes IN winspool.drv;
	STRING    pName,;
	STRING    pPrnProcName,;
	INTEGER   Level,;
	STRING  @ pDatatypes,;
	INTEGER   cbBuf,;
	INTEGER @ pcbNeeded,;
	INTEGER @ pcReturned  
```  
***  


## Parameters:
pName 
[in] Pointer to a null-terminated string that specifies the name of the server on which the print processor resides.

pPrintProcessorName 
[in] Pointer to a null-terminated string that specifies the name of the print processor whose data types are enumerated. 

Level 
[in] Specifies the type of information returned in the pDatatypes buffer. This parameter must be 1. 

pDatatypes 
[out] Pointer to a buffer that receives an array of DATATYPES_INFO_1 structures. 

cbBuf 
[in] Specifies the size, in bytes, of the buffer pointed to by pDatatypes. 

pcbNeeded 
[out] Pointer to a variable that receives the number of bytes copied to the pDatatypes buffer if the function succeeds. 

pcReturned 
[out] Pointer to a variable that receives the number of structures returned in the pDatatypes buffer.  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

