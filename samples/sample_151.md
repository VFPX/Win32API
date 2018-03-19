[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Setting the volume label

## Before you begin:
<DIV style="padding-top: 3px;">See also:</DIV>  
<LI style="padding-bottom: 7px;"><a href="?example=12">Displaying the drive type value</a>[Displaying the drive type value](sample_012.md)  
<LI style="padding-bottom: 7px;"><a href="?example=98">Basic Volume information</a>[Basic Volume information](sample_098.md)  
<LI style="padding-bottom: 7px;"><a href="?example=319">Disk in drive A:</a>[Disk in drive A:](sample_319.md)  
<LI style="padding-bottom: 7px;"><a href="?example=101">Obtaining physical parameters for a drive: sectors, clusters, cylinders...</a>[Obtaining physical parameters for a drive: sectors, clusters, cylinders...](sample_101.md)  
  
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

