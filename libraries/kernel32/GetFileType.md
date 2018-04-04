[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetFileType
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetFileType function retrieves the file type for the specified file.
***  


## Code examples:
[Retrieving file information for the VFP executable running](../../samples/sample_242.md)  
[Using File Mapping for enumerating files opened by Visual FoxPro](../../samples/sample_473.md)  

## Declaration:
```foxpro  
DWORD GetFileType(
  HANDLE hFile   // handle to file
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetFileType IN kernel32;
	INTEGER hFile  
```  
***  


## Parameters:
hFile 
[in] Handle to an open file.   
***  


## Return value:
The return value is one of the following values.   
***  

