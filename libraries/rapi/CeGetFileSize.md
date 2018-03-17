<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CeGetFileSize
Group: Remote Application Programming (RAPI) - Library: rapi    
***  


#### This function retrieves the size, in bytes, of the specified file.
***  


## Code examples:
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  

## Declaration:
```foxpro  
DWORD CeGetFileSize(
  HANDLE hFile,
  LPDWORD lpFileSizeHigh
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG CeGetFileSize IN rapi;
	INTEGER hFile,;
	LONG    lpFileSizeHigh  
```  
***  


## Parameters:
```txt  
hFile
[in] Open handle of the file whose size is being returned.

lpFileSizeHigh
[out] Pointer to the variable where the high-order word of the file size is returned.  
```  
***  


## Return value:
The low-order DWORD of the file size indicates success. If lpFileSizeHigh is non-NULL, the function puts the high-order DWORD of the file size into the variable pointed to by that parameter. If lpFileSizeHigh is NULL, 0xFFFFFFFF indicates failure.  
***  

