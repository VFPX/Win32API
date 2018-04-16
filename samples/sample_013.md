[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving list of available disk drives

## Before you begin:
Find removable, fixed, CD-ROM, RAM disk, and network drives available on the local system.  

See also:

* [Disconnecting USB Mass Storage Device programmatically](sample_553.md)  
* [Mapping and disconnecting network drives in FoxPro application](sample_387.md)  
* [Enumerating network resources](sample_313.md)  
* [Enumerating Volumes and Volume Mounting Points (NTFS)](sample_087.md)  
* [Disk in drive A:](sample_319.md)  
* [How to detect when a removable drive gets connected or disconnected](sample_573.md)  

  
***  


## Code:
```foxpro  
DECLARE INTEGER GetLogicalDrives IN kernel32
DECLARE INTEGER GetDriveType IN kernel32 STRING nDrive

LOCAL nDrivesMask, nIndex, nShift, cDrive
nDrivesMask = GetLogicalDrives()

? "Available disk drives:"

nIndex = 0
DO WHILE .T.
	nShift = BitLShift(1, nIndex)
	cDrive = Chr(nIndex + 65) + ":"

	IF BitAnd(nDrivesMask, nShift) = nShift
		? cDrive, GetDriveType(cDrive)
	ENDIF

	IF nShift > nDrivesMask
		EXIT
	ENDIF

	nIndex = nIndex + 1
ENDDO  
```  
***  


## Listed functions:
[GetDriveType](../libraries/kernel32/GetDriveType.md)  
[GetLogicalDrives](../libraries/kernel32/GetLogicalDrives.md)  

## Comment:
DriveType:  
```txt
0 Unknown   
1 No Root Directory   
2 Removable Disk   
3 Local Disk   
4 Network Drive   
5 Compact Disc   
6 RAM Disk
```

Related VFP functions: DRIVETYPE(), SYS(5), DISKSPACE().  
  
***  

