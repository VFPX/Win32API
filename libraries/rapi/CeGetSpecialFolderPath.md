<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeGetSpecialFolderPath
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function gets the path to a special shell folder.
***  


## Code examples:
[Pocket PC: base class](../../samples/sample_440.md)  

## Declaration:
```foxpro  
DWORD CeGetSpecialFolderPath(
  int nFolder,
  DWORD nBufferLength,
  LPWSTR lpBuffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeGetSpecialFolderPath IN rapi;
	INTEGER nFolder,;
	INTEGER nBufferLength,;
	LONG    lpBuffer  
```  
***  


## Parameters:
```txt  
[in] Value specifying the folder for which to retrieve the location. This parameter can be one of predefined values.

nBufferLength
[in] Size of lpBuffer in characters.

lpBuffer
[out] Long pointer to the buffer for the folder path.  
```  
***  


## Return value:
The length of the returned string indicates success. FALSE indicates a RAPI related failure. To extended error information, call CeRapiGetError.   
***  

