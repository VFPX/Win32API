[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeGetStoreInformation
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function fills in a STORE_INFORMATION structure with the size of the object store and the amount of free space currently in the object store. 
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  

## Declaration:
```foxpro  
BOOL CeGetStoreInformation(
  LPSTORE_INFORMATION lpsi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeGetStoreInformation IN rapi;
	LONG lpsi  
```  
***  


## Parameters:
lpsi 
[out] Pointer to the STORE_INFORMATION structure to be filled in by this function.   
***  


## Return value:
TRUE indicates success. FALSE indicates failure.  
***  


## Comments:
To get extended error information, call the CeGetLastError function. See also CeGlobalMemoryStatus function.  
  
***  

