<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ShellAbout
Group: Shell Functions - Library: shell32    
***  


#### Displays a Shell About dialog box
***  


## Declaration:
```foxpro  
int ShellAbout (
	HWND    hWnd,         // handle of parent window
	LPCTSTR szApp,        // title bar and first line text
	LPCTSTR szOtherStuff, // other dialog text
	HICON   hIcon         // icon to display
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ShellAbout IN shell32;
	INTEGER hwnd,;
	STRING  szApp,;
	STRING  szOtherStuff,;
	INTEGER hIcon  
```  
***  


## Parameters:
```txt  
hWnd
Identifies a parent window

szApp
Points to text that the function displays in the title bar of the Shell About dialog box

szOtherStuff
Points to text that the function displays in the dialog box after the version and copyright information

hIcon
Identifies an icon that the function displays in the dialog box  
```  
***  


## Return value:
If the function succeeds in displaying the dialog box, the return value is TRUE  
***  

