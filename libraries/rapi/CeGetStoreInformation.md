<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeGetStoreInformation
Group: Remote Application Programming (RAPI) - Library: rapi    
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
```txt  
lpsi
[out] Pointer to the STORE_INFORMATION structure to be filled in by this function.  
```  
***  


## Return value:
TRUE indicates success. FALSE indicates failure.  
***  


## Comments:
To get extended error information, call the CeGetLastError function. See also CeGlobalMemoryStatus function.  
  
***  

