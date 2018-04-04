[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumPrinterDrivers
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### Enumerates the printer drivers installed on a specified printer server.
***  


## Code examples:
[Enumerating printer drivers installed](../../samples/sample_082.md)  

## Declaration:
```foxpro  
BOOL EnumPrinterDrivers(
  LPTSTR pName,        // printer server name
  LPTSTR pEnvironment, // environment name
  DWORD Level,         // information level
  LPBYTE pDriverInfo,  // driver information buffer
  DWORD cbBuf,         // size of driver information buffer
  LPDWORD pcbNeeded,   // bytes received or required
  LPDWORD pcReturned   // number of drivers received
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumPrinterDrivers IN winspool.drv;
	STRING    pName,;
	STRING    pEnvironment,;
	INTEGER   Level,;
	STRING  @ pDriverInfo,;
	INTEGER   cdBuf,;
	INTEGER @ pcbNeeded,;
	INTEGER @ pcReturned  
```  
***  


## Parameters:
pName 
[in] Pointer to a null-terminated string that specifies the name of the server on which the printer drivers are enumerated. 

pEnvironment 
[in] Pointer to a null-terminated string that specifies the environment 

Level 
[in] Specifies the type of information structure returned in the pDriverInfo buffer. 

pDriverInfo 
[in] Pointer to a buffer that receives an array of DRIVER_INFO_* structures, as specified by Level. 

cbBuf 
[in] Specifies the size, in bytes, of the buffer pointed to by pDriverInfo. 

pcbNeeded 
[out] Pointer to a variable that receives the number of bytes copied to the pDriverInfo buffer if the function succeeds. 

pcReturned 
[out] Pointer to a variable that receives the number of structures returned in the pDriverInfo buffer. 
  
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
Not like some other enumerating functions this one does not need a call-back procedure. It returns data in an array.  
  
***  

