[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SearchPath
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SearchPath function searches for the specified file. 
***  


## Code examples:
[Searching for the specified file using the SearchPath](../../samples/sample_250.md)  

## Declaration:
```foxpro  
DWORD SearchPath(
  LPCTSTR lpPath,      // search path
  LPCTSTR lpFileName,  // file name
  LPCTSTR lpExtension, // file extension
  DWORD nBufferLength, // size of buffer
  LPTSTR lpBuffer,     // found file name buffer
  LPTSTR *lpFilePart   // file component
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SearchPath IN kernel32;
	STRING    lpPath,;
	STRING    lpFileName,;
	STRING    lpExtension,;
	INTEGER   nBufLen,;
	STRING  @ lpBuffer,;
	INTEGER @ lpFilePart  
```  
***  


## Parameters:
lpPath 
[in] Pointer to a null-terminated string that specifies the path to be searched for the file. 

lpFileName 
[in] Pointer to a null-terminated string that specifies the name of the file to search for. 

lpExtension 
[in] Pointer to a null-terminated string that specifies an extension to be added to the file name when searching for the file. 

nBufferLength 
[in] Specifies the length, in TCHARs, of the buffer that receives the valid path and file name. 

lpBuffer 
[out] Pointer to the buffer that receives the path and file name of the file found. 

lpFilePart 
[out] Pointer to the variable that receives the address (within lpBuffer) of the last component of the valid path and file name, which is the address of the character immediately following the final backslash (\) in the path.   
***  


## Return value:
If the function succeeds, the value returned is the length, in TCHARs, of the string copied to the buffer, not including the terminating null character.   
***  


## Comments:
If the path to be searched for the file is NULL, the function searches for a matching file in the following directories in the following sequence: 

* The directory from which the application loaded.   
* The current directory.   
* The Windows system directory.  
* The Windows directory.  
* The directories that are listed in the PATH environment variable.   

***  

