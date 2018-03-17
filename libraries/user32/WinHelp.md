<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WinHelp
Group: Shell Functions - Library: user32    
***  


#### The WinHelp function starts Windows Help (WINHELP.EXE) and passes additional data indicating the nature of the help requested by the application
***  


## Declaration:
```foxpro  
BOOL WinHelp(
    HWND  hwnd,	// handle of window requesting Help
    LPCTSTR  lpszHelp,	// address of directory-path string
    UINT  uCommand,	// type of Help
    DWORD  dwData 	// additional data
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHelp IN user32 As "WinHelpA";
	INTEGER hwnd,;
	STRING  lpHelpFile,;
	INTEGER wCommand,;
	INTEGER dwData
  
```  
***  


## Parameters:
```txt  
hwnd
Identifies the window requesting Help

lpszHelp
Points to a null-terminated string containing the path, if necessary, and the name of the Help file

uCommand
Specifies the type of help requested

dwData
Specifies additional data
  
```  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
Structure HELPWININFO contains the size and position of either a primary or a secondary Help window. An application can set this information by calling the WinHelp function with the HELP_SETWINPOS value  
  
***  

