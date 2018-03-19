
# Displaying the drive type value

## Before you begin:
<DIV style="padding-top: 3px;">See also:</DIV>  
<LI style="padding-bottom: 7px;"><a href="?example=98">Basic Volume information</a>[Basic Volume information](sample_098.md)  
<LI style="padding-bottom: 7px;"><a href="?example=151">Setting the volume label</a>[Setting the volume label](sample_151.md)  
<LI style="padding-bottom: 7px;"><a href="?example=319">Disk in drive A:</a>[Disk in drive A:](sample_319.md)  
<LI style="padding-bottom: 7px;"><a href="?example=101">Obtaining physical parameters for a drive: sectors, clusters, cylinders...</a>[Obtaining physical parameters for a drive: sectors, clusters, cylinders...](sample_101.md)  
  
***  


## Code:
```foxpro  
#DEFINE DRIVE_UNKNOWN     0
#DEFINE DRIVE_NO_ROOT_DIR 1
#DEFINE DRIVE_REMOVABLE   2
#DEFINE DRIVE_FIXED       3
#DEFINE DRIVE_REMOTE      4
#DEFINE DRIVE_CDROM       5
#DEFINE DRIVE_RAMDISK     6

DECLARE INTEGER GetDriveType IN kernel32 STRING nDrive

DECLARE INTEGER RealDriveType IN shell32;
	INTEGER iDrive, INTEGER fOKToHitNet

LOCAL nIndex, nType

FOR nIndex=Asc("A") TO Asc("Z")

	* both functions return identical results
	nType = RealDriveType(nIndex-65, 0)
*	nType = GetDriveType(Chr(nIndex) + ":")

	DO CASE
	CASE nType = DRIVE_REMOVABLE
		? Chr(nIndex)+":", "removable"
	CASE nType = DRIVE_FIXED
		? Chr(nIndex)+":", "fixed"
	CASE nType = DRIVE_REMOTE
		? Chr(nIndex)+":", "remote"
	CASE nType = DRIVE_CDROM
		? Chr(nIndex)+":", "CDROM"
	CASE nType = DRIVE_RAMDISK
		? Chr(nIndex)+":", "RAM"
	ENDCASE
ENDFOR  
```  
***  


## Listed functions:
[GetDriveType](../libraries/kernel32/GetDriveType.md)  
[RealDriveType](../libraries/shell32/RealDriveType.md)  
