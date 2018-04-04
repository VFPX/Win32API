[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetVolumeInformation
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves information about a file system and volume whose root directory is specified.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  
[Basic Volume information](../../samples/sample_098.md)  
[Disk in drive A:](../../samples/sample_319.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  

## Declaration:
```foxpro  
BOOL GetVolumeInformation(
  LPCTSTR lpRootPathName,           // root directory
  LPTSTR lpVolumeNameBuffer,        // volume name buffer
  DWORD nVolumeNameSize,            // length of name buffer
  LPDWORD lpVolumeSerialNumber,     // volume serial number
  LPDWORD lpMaximumComponentLength, // maximum file name length
  LPDWORD lpFileSystemFlags,        // file system options
  LPTSTR lpFileSystemNameBuffer,    // file system name buffer
  DWORD nFileSystemNameSize         // length of file system name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetVolumeInformation IN kernel32;
	STRING    lpRootPathName,;
	STRING  @ lpVolumeNameBuffer,;
	INTEGER   nVolumeNameSize,;
	INTEGER @ lpVolumeSerialNumber,;
	INTEGER @ lpMaximumComponentLength,;
	INTEGER @ lpFlags,;
	STRING  @ lpFileSystemNameBuffer,;
	INTEGER   nFileSystemNameSize
  
```  
***  


## Parameters:
lpRootPathName 
[in] Pointer to a string that contains the root directory of the volume to be described. 

lpVolumeNameBuffer 
[out] Pointer to a buffer that receives the name of the specified volume. 

nVolumeNameSize 
[in] Specifies the length, in TCHARs, of the volume name buffer. 

lpVolumeSerialNumber 
[out] Pointer to a variable that receives the volume serial number. 

lpMaximumComponentLength 
[out] Pointer to a variable that receives the maximum length, in TCHARs, of a file name component supported by the specified file system. 

lpFileSystemFlags 
[out] Pointer to a variable that receives flags associated with the specified file system. 

lpFileSystemNameBuffer 
[out] Pointer to a buffer that receives the name of the file system (such as FAT or NTFS). 

nFileSystemNameSize 
[in] Specifies the length, in TCHARs, of the file system name buffer.  
***  


## Return value:
If all the requested information is retrieved, the return value is nonzero.  
***  


## Comments:
If you are attempting to obtain information about a floppy drive that does not have a floppy disk or a CD-ROM drive that does not have a compact disc, the system displays a message box asking the user to insert a floppy disk or a compact disc, respectively. To prevent the system from displaying this message box, call the function with SEM_FAILCRITICALERRORS.  
  
With this function you can check "no-disk" status of a floppy drive or CD-ROM drive, and long filenames support on a volume.  
  
***  

