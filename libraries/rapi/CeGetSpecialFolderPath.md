[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeGetSpecialFolderPath
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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
[in] Value specifying the folder for which to retrieve the location. This parameter can be one of predefined values.

nBufferLength 
[in] Size of lpBuffer in characters. 

lpBuffer 
[out] Long pointer to the buffer for the folder path.   
***  


## Return value:
The length of the returned string indicates success. FALSE indicates a RAPI related failure. To extended error information, call CeRapiGetError.   
***  

