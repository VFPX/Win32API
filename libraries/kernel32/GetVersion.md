[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetVersion
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetVersion function returns the current version number of Windows and information about the operating system platform
***  


## Code examples:
[OS version and revision](../../samples/sample_022.md)  
[Simple printer queue monitor: deletes, pauses, resumes print jobs for local printer](../../samples/sample_373.md)  

## Declaration:
```foxpro  
DWORD GetVersion(VOID)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetVersion IN kernel32
  
```  
***  


## Parameters:
This function has no parameters  
***  


## Return value:
If the function succeeds, the return value is the major and minor version numbers of Windows and a code specifying the operating system platform. The low-order word contains the version number of Windows. The high-order byte specifies the minor version (revision) number, in hexadecimal notation. The low-order byte specifies the major version number, in hexadecimal notation  
***  


## Comments:
The very basic information is returned. The extended version gives more, though more efforts needed to convert the result into FoxPro variables  
  
***  

