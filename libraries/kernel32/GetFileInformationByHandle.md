[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileInformationByHandle
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetFileInformationByHandle function retrieves file information for a specified file.
***  


## Code examples:
[Retrieving file information for the VFP executable running](../../samples/sample_242.md)  
[Running MSDOS Shell as a child process with redirected input and output (smarter RUN command)](../../samples/sample_477.md)  

## Declaration:
```foxpro  
BOOL GetFileInformationByHandle(
  HANDLE hFile,                           // handle to file
  LPBY_HANDLE_FILE_INFORMATION lpFileInfo // buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileInformationByHandle IN kernel32;
	INTEGER   hFile,;
	STRING  @ lpFileInfo  
```  
***  


## Parameters:
hFile 
[in] Handle to the file for which to obtain information. 

lpFileInformation 
[out] Pointer to a BY_HANDLE_FILE_INFORMATION structure that receives the file information.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

