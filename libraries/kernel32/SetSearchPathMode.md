<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetSearchPathMode
Group: File Management - Library: kernel32    
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
```txt  
Flags [in]
The search mode to use -- a predefned value.  
```  
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
  
See also: SearchPath   
  
***  

