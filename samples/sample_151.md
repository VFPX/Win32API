[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Setting the volume label

## Before you begin:

See also:  
* [Displaying the drive type value](sample_012.md)  
* [Basic Volume information](sample_098.md)  
* [Disk in drive A:](sample_319.md)  
* [Obtaining physical parameters for a drive: sectors, clusters, cylinders...](sample_101.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER GetLastError IN kernel32

DECLARE INTEGER SetVolumeLabel IN kernel32;
	STRING lpRootPathName, STRING lpVolumeName

IF SetVolumeLabel ("A:\", "VolumeA") = 0
	*    3 = The system cannot find the path specified
	*    5 = Access is denied
	*   21 = The device is not ready
	*  123 = ERROR_INVALID_NAME
	* 1235 = The request was aborted
	? "Error code:", GetLastError()
ENDIF  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[SetVolumeLabel](../libraries/kernel32/SetVolumeLabel.md)  

## Comment:
In some cases you have unspecified error 0, e.g. if the floppy is write-protected.  
  
***  

