<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : EnumPrintProcessors
Group: Printing and Print Spooler - Library: winspool.drv    
***  


#### The EnumPrintProcessors function enumerates the print processors installed on the specified server.
***  


## Code examples:
[Enumerating print processors and supporting data types installed on the specified server](../../samples/sample_333.md)  

## Declaration:
```foxpro  
BOOL EnumPrintProcessors(
  LPTSTR pName,                // print server name
  LPTSTR pEnvironment,         // environment name
  DWORD Level,                 // information level
  LPBYTE pPrintProcessorInfo,  // processor data buffer
  DWORD cbBuf,                 // size of data buffer
  LPDWORD pcbNeeded,           // bytes received or required
  LPDWORD pcReturned           // number of processors
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumPrintProcessors IN winspool.drv;
	STRING    pName,;
	STRING    pEnvir,;
	INTEGER   Level,;
	STRING  @ pPrintProcInfo,;
	INTEGER   cbBuf,;
	INTEGER @ pcbNeeded,;
	INTEGER @ pcReturned
  
```  
***  


## Parameters:
```txt  
pName
[in] Pointer to a null-terminated string that specifies the name of the server on which the print processors reside.

pEnvironment
[in] Pointer to a null-terminated string that specifies the environment.

Level
[in] Specifies the type of information returned in the pPrintProcessorInfo buffer. This parameter must be 1.

pPrintProcessorInfo
[out] Pointer to a buffer that receives an array of PRINTPROCESSOR_INFO_1 structures.

cbBuf
[in] Specifies the size, in bytes, of the buffer pointed to by pPrintProcessorInfo.

pcbNeeded
[out] Pointer to a variable that receives the number of bytes copied to the pPrintProcessorInfo buffer if the function succeeds.

pcReturned
[out] Pointer to a variable that receives the number of structures returned in the pPrintProcessorInfo buffer.  
```  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

