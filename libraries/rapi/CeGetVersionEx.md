[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeGetVersionEx
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function obtains extended information about the version of the operating system that is currently running. 
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  

## Declaration:
```foxpro  
BOOL CeGetVersionEx(
  LPCEOSVERSIONINFO lpVersionInformation
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeGetVersionEx IN rapi;
	LONG lpVersionInformation  
```  
***  


## Parameters:
lpVersionInformation 
[out] Long pointer to an CEOSVERSIONINFO data structure that the function fills with operating system version information.   
***  


## Return value:
Nonzero indicates success. Zero indicates failure.  
***  


## Comments:
Before calling the CeGetVersionEx function, set the dwOSVersionInfoSize member of the CEOSVERSIONINFO data structure to sizeof(CEOSVERSIONINFO).   
  
Nonzero indicates success. Zero indicates failure. To determine if a function failed because of RAPI errors, call CeRapiGetError. To determine if a function failed because of non-RAPI errors, call CeGetLastError.  
  
***  

