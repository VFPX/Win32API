[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindFirstVolume
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Returns the name of a volume on a computer. This call is used to begin scanning the volumes of a computer.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
HANDLE FindFirstVolume(
	LPTSTR lpszVolumeName,
	DWORD cchBufferLength
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindFirstVolume IN kernel32;
	STRING lpszVolumeName,;
	LONG cchBufferLength
  
```  
***  


## Parameters:
lpszVolumeName 
[out] Pointer to a buffer that receives a null-terminated string that specifies the unique volume name of the first volume found. 

cchBufferLength 
[in] Length of the buffer to receive the name, in TCHARs.  
***  


## Return value:
If the function fails to find any volumes, the return value is the INVALID_HANDLE_VALUE error code.  
***  


## Comments:
If the function succeeds, the return value is a search handle used in a subsequent call to the FindNextVolume and FindVolumeClose functions.  
  
See also: [FindFirstVolumeMountPoint](../kernel32/FindFirstVolumeMountPoint.md), [GetVolumeInformation](../kernel32/GetVolumeInformation.md).  
  
***  

