[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetVolumeLabel
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
lpRootPathName 
[in] Pointer to a null-terminated string specifying the root directory of a file system volume. 

lpVolumeName 
[in] Pointer to a string specifying a name for the volume.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
There is no <Strong>GetVolumeLabel</Strong> API function. Function GetVolumeInformation retrieves information about a file system and volume whose root directory is specified.  
  
***  

