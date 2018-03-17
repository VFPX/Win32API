<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetVolumeLabel
Group: File System - Library: kernel32    
***  


#### The SetVolumeLabel function sets the label of a file system volume.
***  


## Code examples:
[Setting the volume label](../../samples/sample_151.md)  

## Declaration:
```foxpro  
BOOL SetVolumeLabel(
  LPCTSTR lpRootPathName,  // name of volume root directory
  LPCTSTR lpVolumeName     // name for the volume
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetVolumeLabel IN kernel32;
	STRING lpRootPathName,;
	STRING lpVolumeName  
```  
***  


## Parameters:
```txt  
lpRootPathName
[in] Pointer to a null-terminated string specifying the root directory of a file system volume.

lpVolumeName
[in] Pointer to a string specifying a name for the volume.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
There is no <Strong>GetVolumeLabel</Strong> API function. Function GetVolumeInformation retrieves information about a file system and volume whose root directory is specified.  
  
***  

