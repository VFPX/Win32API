[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetVolumeNameForVolumeMountPoint
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Takes a volume mount point or root directory and returns the corresponding unique volume name.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL GetVolumeNameForVolumeMountPoint(
  LPCTSTR lpszVolumeMountPoint,
  LPTSTR lpszVolumeName,
  DWORD cchBufferLength
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetVolumeNameForVolumeMountPoint IN kernel32;
	STRING lpszVolumeMountPoint,;
	STRING @lpszVolumeName,;
	LONG cchBufferLength  
```  
***  


## Parameters:
lpszVolumeMountPoint 
[in] Pointer to a string that contains either the path of a volume mount point with a trailing backslash (\) or a drive letter indicating a root directory in the form "D:\". 

lpszVolumeName 
[out] Pointer to a string that receives the volume name. This name is a unique volume name of the form "\\?\Volume{GUID}\" where GUID is the GUID that identifies the volume. 

cchBufferLength 
[in] Length of the output buffer, in TCHARs. A reasonable size for the buffer to accommodate the largest possible volume name is 50 characters.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The <Em>lpszVolumeMountPoint</Em> parameter may be a drive letter with appended backslash (\), such as "D:\". Alternatively, it may be a path to a volume mount point, again with appended backslash (\), such as "c:\mnt\edrive\".  
  
***  

