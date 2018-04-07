[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetSearchPathMode
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Sets the per-process mode that the SearchPath function uses when locating files.
***  


## Declaration:
```foxpro  
BOOL SetSearchPathMode(
	__in  DWORD Flags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetSearchPathMode IN kernel32;
	LONG nFlags  
```  
***  


## Parameters:
Flags [in]
The search mode to use -- a predefned value.  
***  


## Return value:
Returns a nonzero value if the operation completes successfully.  
***  


## Comments:
Minimum OS: Windows 7  
  
BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE (0x00000001)  
Enable safe process search mode for the process.  
  
BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE (0x00010000)  
Disable safe process search mode for the process.  
  
BASE_SEARCH_PATH_PERMANENT (0x00008000)  
Optional flag to use in combination with BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE to make this mode permanent for this process.  
  
See also: [SearchPath](../kernel32/SearchPath.md).  
  
***  

