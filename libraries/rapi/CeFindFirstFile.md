<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeFindFirstFile
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function searches a directory for a file whose name matches the specified filename. CeFindFirstFile examines subdirectory names as well as filenames.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
HANDLE CeFindFirstFile(
	LPCWSTR lpFileName,
	LPCE_FIND_DATA lpFindFileData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CeFindFirstFile IN rapi;
	STRING   lpFileName,;
	STRING @ lpFindFileData
  
```  
***  


## Parameters:
```txt  
lpFileName
[in] Long pointer to a null-terminated string that specifies a valid directory or path and filename, which can contain wildcard characters (* and ?).

lpFindFileData
[out] Long pointer to the WIN32_FIND_DATA structure that receives information about the found file or subdirectory.  
```  
***  


## Return value:
A search handle, used in a subsequent call to CeFindNextFile or CeFindClose, indicates success. INVALID_HANDLE_VALUE indicates failure.   
***  


## Comments:
See also CeCloseHandle, CeFindNextFile functions.  
  
***  

