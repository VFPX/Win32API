[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPrintProcessorDirectory
Group: [Printing and Print Spooler](../../functions_group.md#Printing_and_Print_Spooler)  -  Library: [winspool.drv](../../Libraries.md#winspool.drv)  
***  


#### The GetPrintProcessorDirectory function retrieves the path for the print processor on the specified server. 
***  


## Code examples:
[Retrieving the path of the printer-driver directory and printer-processor directory](../../samples/sample_359.md)  

## Declaration:
```foxpro  
BOOL GetPrintProcessorDirectory(
  LPTSTR pName,                // server name
  LPTSTR pEnvironment,         // environment name
  DWORD Level,                 // information level
  LPBYTE pPrintProcessorInfo,  // path buffer
  DWORD cbBuf,                 // size of path buffer
  LPDWORD pcbNeeded            // bytes received or required
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPrintProcessorDirectory IN winspool.drv;
	STRING    pName,;
	STRING    pEnvir,;
	INTEGER   Lvl,;
	STRING  @ pPrintProcInfo,;
	INTEGER   cbBuf,;
	INTEGER @ pcbNeeded  
```  
***  


## Parameters:
pName 
[in] Pointer to a null-terminated string that specifies the name of the server. If this parameter is NULL, a local path is returned.

pEnvironment 
[in] Pointer to a null-terminated string that specifies the environment (for example, "Windows NT x86", "Windows NT R4000", "Windows NT Alpha_AXP", or "Windows 4.0").

Level 
[in] Specifies the structure level. This value must be 1. 

pPrintProcessorInfo 
[out] Pointer to a buffer that receives the path.

cbBuf 
[in] Specifies the size of the buffer pointed to by pPrintProcessorInfo. 

pcbNeeded 
[out] Pointer to a value that specifies the number of bytes copied if the function succeeds, or the number of bytes required if cbBuf is too small.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  

