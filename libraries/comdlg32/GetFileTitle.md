[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileTitle
Group: [Common Dialog Box](../../functions_group.md#Common_Dialog_Box)  -  Library: [comdlg32](../../Libraries.md#comdlg32)  
***  


#### Retrieves the name of the specified file.
***  


## Code examples:
[Extracting the name and extension parts of a path string](../../samples/sample_118.md)  

## Declaration:
```foxpro  
short GetFileTitle(
  LPCTSTR lpszFile,  // path and file name
  LPTSTR lpszTitle,  // file name buffer
  WORD cbBuf         // length of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetFileTitle IN Comdlg32;
	STRING   lpszFile,;
	STRING @ lpszTitle,;
	INTEGER  cbBuf  
```  
***  


## Parameters:
lpszFile 
[in] Pointer to the name and location of a file. 

lpszTitle 
[out] Pointer to a buffer that receives the name of the file. 

cbBuf 
[in] Specifies the length, in TCHARs, of the buffer pointed to by the lpszTitle parameter.  
***  


## Return value:
If the function succeeds, the return value is zero. If the file name is invalid, the return value is unknown. 
  
***  


## Comments:
In other words this function extracts the file and extension parts from a legal Win32 path string. Although that does not mean that file should exist.  
  
***  

