<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetFileAttributes
Group: File Management - Library: kernel32    
***  


#### Sets a file"s attributes.

***  


## Code examples:
[Changing file attributes](../../samples/sample_103.md)  

## Declaration:
```foxpro  
BOOL SetFileAttributes(
  LPCTSTR lpFileName,      // file name
  DWORD dwFileAttributes   // attributes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT SetFileAttributes IN kernel32;
	STRING lpFileName,;
	INTEGER dwFileAttributes  
```  
***  


## Parameters:
```txt  
lpFileName
[in] Pointer to a string that specifies the name of the file whose attributes are to be set.

dwFileAttributes
[in] Specifies the file attributes to set for the file.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
DOS command ATTRIB can be used for the same purpose:  
<div class="precode">ATTRIB -R c:\mydir\*.* /S  
</div>  
  
***  

