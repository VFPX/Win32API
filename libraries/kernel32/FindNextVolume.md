<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindNextVolume
Group: File System - Library: kernel32    
***  


#### Continues a volume search started by a call to the FindFirstVolume function.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL FindNextVolume(
	HANDLE hFindVolume,
	LPTSTR lpszVolumeName,
	DWORD cchBufferLength
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindNextVolume IN kernel32;
	INTEGER hFindVolume,;
	STRING @lpszVolumeName,;
	LONG cchBufferLength  
```  
***  


## Parameters:
```txt  
hFindVolume
[in] Volume search handle returned by a previous call to the FindFirstVolume function.

lpszVolumeName
[out] Pointer to a string that receives the unique volume name found.

cchBufferLength
[in] Length of the buffer that receives the name, in TCHARs.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: FindFirstVolume, FindVolumeClose, FindFirstVolumeMountPoint, GetVolumeInformation   
  
***  

