[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDriveType
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetDriveType function determines whether a disk drive is a removable, fixed, CD-ROM, RAM disk, or network drive
***  


## Code examples:
[Displaying the drive type value](../../samples/sample_012.md)  
[Retrieving list of available disk drives](../../samples/sample_013.md)  
[Using the GetLogicalDriveStrings](../../samples/sample_017.md)  
[Retrieving information about MS-DOS device names using QueryDosDevice (WinNT only)](../../samples/sample_241.md)  
[Mapping and disconnecting network drives](../../samples/sample_387.md)  
[Disconnecting USB Mass Storage Device programmatically](../../samples/sample_553.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  

## Declaration:
```foxpro  
UINT GetDriveType(
  LPCTSTR lpRootPathName   // root directory
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDriveType IN kernel32 STRING nDrive  
```  
***  


## Parameters:
lpRootPathName 
[in] Pointer to a null-terminated string that specifies the root directory of the disk to return information about. A trailing backslash is required. If lpRootPathName is NULL, the function uses the root of the current directory  
***  


## Return value:
The return value specifies the type of drive  
***  


## Comments:
```txt
#DEFINE DRIVE_UNKNOWN 0  
#DEFINE DRIVE_NO_ROOT_DIR 1  
#DEFINE DRIVE_REMOVABLE 2  
#DEFINE DRIVE_FIXED 3  
#DEFINE DRIVE_REMOTE 4  
#DEFINE DRIVE_CDROM 5  
#DEFINE DRIVE_RAMDISK 6
```
  
See also: [RealDriveType](../shell32/RealDriveType.md).  
  
***  

