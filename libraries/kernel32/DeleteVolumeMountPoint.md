[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeleteVolumeMountPoint
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Unmounts the volume from the specified volume mount point.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL DeleteVolumeMountPoint(
	LPCTSTR lpszVolumeMountPoint
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeleteVolumeMountPoint IN kernel32;
	STRING lpszVolumeMountPoint  
```  
***  


## Parameters:
lpszVolumeMountPoint 
[in] Pointer to a string that indicates the volume mount point to be unmounted.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The <Em>lpszVolumeMountPoint</Em> may be a root directory (X:\, in which case the DOS drive letter assignment is removed) or a directory on a volume (X:\mnt\). A trailing backslash is required.   
  
Handle with care.  
  
***  

