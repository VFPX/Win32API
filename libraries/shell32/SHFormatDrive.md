[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHFormatDrive
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### The SHFormatDrive API provides access to the Shell"s format dialog box. This allows applications that want to format disks to bring up the same dialog box that the Shell uses for disk formatting.

***  


## Code examples:
[Disk in drive A:](../../samples/sample_319.md)  

## Declaration:
```foxpro  
DWORD WINAPI SHFormatDrive(
	HWND hwnd,
	UINT drive,
	UINT fmtID,
	UINT options);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHFormatDrive IN shell32;
	INTEGER HWND,;
	INTEGER lpDrive,;
	INTEGER fmtID,;
	INTEGER options  
```  
***  


## Parameters:
hwnd
[in] The window handle of the window that will own the dialog.

drive
[in] The 0 based (A: == 0) drive number of the drive to format.

fmtID
[in] Currently must be set to SHFMT_ID_DEFAULT.

options
[in] Predefined options.
  
***  


## Return value:
The return is either one of the SHFMT_* values, or if the returned DWORD value is not == to one of these values, then the return is the physical format ID of the last successful format.  
***  


## Comments:
This function looks some undocumented. Though there is a MSDN link describing it, it is not really a regular description as it is for other Shell functions.  
  

  
***  

