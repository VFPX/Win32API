<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindClose
Group: File Management - Library: kernel32    
***  


#### The FindClose function closes the specified search handle. The FindFirstFile and FindNextFile functions use the search handle to locate files with names that match a given name.
***  


## Code examples:
[Building a tree of subdirectories for a given path using FindFile functions](../../samples/sample_236.md)  

## Declaration:
```foxpro  
BOOL FindClose(
  HANDLE hFindFile   // file search handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindClose IN kernel32;
	INTEGER hFindFile  
```  
***  


## Parameters:
```txt  
hFindFile
[in/out] File search handle. This handle must have been previously opened by the FindFirstFile function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

