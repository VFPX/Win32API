[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeFindAllFiles
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
***  


#### This function retrieves information about all files and directories in the given directory of the Windows CE object store. 
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
BOOL CeFindAllFiles(
  LPCWSTR szPath,
  DWORD dwFlags,
  LPDWORD lpdwFoundCount,
  LPLPCE_FIND_DATA ppFindDataArray
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeFindAllFiles IN rapi;
	STRING    szPath,;
	INTEGER   dwFlags,;
	INTEGER @ lpdwFoundCount,;
	INTEGER @ ppFindDataArray  
```  
***  


## Parameters:
szPath 
[in] Null-terminated string contains the name of the path in which to search for files.

dwFlags 
[in] Combination of filter and retrieval flags. The filter flags specify what kinds of files to document, and the retrieval flags specify which members of the CE_FIND_DATA structure to retrieve. 

lpdwFoundCount 
[out] Long pointer to a variable that receives a count of the items found. 

ppFindDataArray 
[out] Pointer to the pointer to an array of CE_FIND_DATA structures that receive information about the found items.  
***  


## Return value:
TRUE indicates success. FALSE indicates failure.  
***  


## Comments:
The function copies information to an array of CE_FIND_DATA structures.   
  
It is the application"s responsibility to free the memory used by the <Em>ppFindDataArray</Em> array. To free the memory you must call CeRapiFreeBuffer.   
  
***  

