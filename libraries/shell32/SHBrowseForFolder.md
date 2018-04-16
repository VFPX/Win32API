[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHBrowseForFolder
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Displays a dialog box that enables the user to select a Shell folder. 
***  


## Code examples:
[Displaying system dialog that selects a folder](../../samples/sample_364.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  

## Declaration:
```foxpro  
LPITEMIDLIST SHBrowseForFolder(
	LPBROWSEINFO lpbi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHBrowseForFolder IN shell32;
	STRING @ lpbi  
```  
***  


## Parameters:
lpbi
[in, out] Pointer to a BROWSEINFO structure that contains information used to display the dialog box.   
***  


## Return value:
Returns a pointer to an item identifier list (PIDL) that specifies the location of the selected folder relative to the root of the namespace. If the user chooses the Cancel button in the dialog box, the return value is NULL.  
***  


## Comments:
Starting with VFP version 7 the original <a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/fox7help/html/lnggetdirlp_rp.asp">GETDIR</a> function is changed to be a wrapper around the SHBrowseForFolder function.   
  
The SHGetPathFromIDList will return the path of the selected folder.   
  
* * *  
Windows Shell script:  
```foxpro
oShell = CREATEOBJECT("Shell.Application")  
  
oFolder = oShell.Application.BrowseForFolder(_screen.HWnd,;  
	"Select Folder", 1, "c:\Program Files")  
  
IF NOT ISNULL(oFolder)  
	? oFolder.self.Path  
ENDIF
```

***  

