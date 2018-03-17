<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindVolumeClose
Group: File System - Library: kernel32    
***  


#### Closes the specified volume search handle created with the FindFirstVolume and FindNextVolume call.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL FindVolumeClose(
	HANDLE hFindVolume
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindVolumeClose IN kernel32;
	INTEGER hFindVolume
  
```  
***  


## Parameters:
```txt  
hFindVolume
[in] Volume search handle to close. This handle must have been previously opened by the FindFirstVolume function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

