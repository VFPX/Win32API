<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetFileType
Group: File Management - Library: kernel32    
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
```txt  
hFile
[in] Handle to an open file.  
```  
***  


## Return value:
The return value is one of the following values.   
***  

