[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CeGetFileSize
Group: [Remote Application Programming (RAPI)](../../functions_group.md#Remote_Application_Programming_(RAPI))  -  Library: [rapi](../../Libraries.md#rapi)  
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
hFile 
[in] Open handle of the file whose size is being returned.

lpFileSizeHigh 
[out] Pointer to the variable where the high-order word of the file size is returned.  
***  


## Return value:
The low-order DWORD of the file size indicates success. If lpFileSizeHigh is non-NULL, the function puts the high-order DWORD of the file size into the variable pointed to by that parameter. If lpFileSizeHigh is NULL, 0xFFFFFFFF indicates failure.  
***  

